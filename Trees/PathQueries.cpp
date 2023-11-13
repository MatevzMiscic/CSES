#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> edges;
vector<int> vals;
vector<int> sizes;
vector<int> depth;
vector<int> par;
vector<int> id;
vector<int> top;
int counter = 0;


struct BIT{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    BIT(int n): n(n){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        arr[i] += x;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] += x;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum += tree[j];
        return sum;
    }
};


void dfs(int u, int p, int d){
    sizes[u] = 1;
    depth[u] = d;
    par[u] = p;
    for(int v : edges[u]){
        if(v != p){
            dfs(v, u, d + 1);
            sizes[u] += sizes[v];
        }
    }
}

void hl(int u, int p, int tp){
    id[u] = counter++;
    top[u] = tp;
    int hchild = -1, hsize = -1;
    for(int v : edges[u]){
        if(v != p){
            if(sizes[v] > hsize){
                hsize = sizes[v];
                hchild = v;
            }
        }
    }
    //printf("node: %d, hchild: %d, hsize: %d\n", u, hchild, hsize);
    if(hchild == -1) return;
    hl(hchild, u, tp);
    for(int v : edges[u]){
        if(v != p && v != hchild){
            hl(v, u, v);
        }
    }
}

int main(){
    int n, q, v, a, b;
    scanf("%d %d", &n, &q);
    edges.assign(n, vector<int>());
    vals.assign(n, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v);
        vals[i] = v;
    }
    for(int i = 0; i < n - 1; ++i){
        scanf("%d %d", &a, &b);
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    sizes.assign(n, 0);
    depth.assign(n, 0);
    par.assign(n, 0);
    dfs(0, -1, 0);
    id.assign(n, 0);
    top.assign(n, 0);
    hl(0, -1, 0);
    /*
    for(int s : sizes) printf("%d ", s);
    printf("\n");
    for(int s : depth) printf("%d ", s);
    printf("\n");
    for(int s : par) printf("%d ", s);
    printf("\n");
    for(int i : id) printf("%d ", i);
    printf("\n");
    for(int t : top) printf("%d ", t);
    printf("\n");
    */
    BIT bit(n);
    for(int u = 0; u < n; ++u){
        bit.add(id[u], vals[u]);
    }
    int t, u, x;
    for(int i = 0; i < q; ++i){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d", &u, &x);
            bit.set(id[u - 1], x);
        }else{
            scanf("%d", &u);
            u -= 1;
            ll sum = 0;
            while(top[u] > 0){
                //printf("[%d, %d]\n", id[top[u]], id[u]);
                sum += bit.query(id[u]) - bit.query(id[top[u]] - 1);
                u = par[top[u]];
            }
            sum += bit.query(id[u]);
            printf("%lld\n", sum);
        }
    }
}
