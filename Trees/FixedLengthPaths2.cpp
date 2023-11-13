#include <cstdio>
#include <vector>
#include <unordered_map>
 
using namespace std;
using ll = long long;

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
    ll query(int a, int b){
        ll sum = query(b);
        if(a > 0) sum -= query(a - 1);
        return sum;
    }
    void clearall(int a, int b){
        for(int j = a; j <= b; ++j) set(j, 0);
    }
};

int n, k1, k2, a, b, maxdepth;
ll counter = 0;
vector<vector<int>> edges;
vector<int> sizes;
vector<bool> removed;
BIT depth(2e5);
 
 
int dfs(int u, int p){
    sizes[u] = 1;
    for(int v : edges[u]){
        if(v != p && !removed[v]) sizes[u] += dfs(v, u);
    }
    return sizes[u];
}
 
int centroid(int u, int p, int s){
    for(int v : edges[u]){
        if(v != p && !removed[v] && 2*sizes[v] > s) return centroid(v, u, s);
    }
    return u;
}
 
void first(int u, int p, int d){
    if(d > k2) return;
    //printf("%d: +%d\n", u + 1, depth[k - d]);
    counter += depth.query(k1 - d, k2 - d);
    for(int v : edges[u]){
        if(v != p && !removed[v]) first(v, u, d + 1);
    }
}
 
void second(int u, int p, int d){
    if(d > k2) return;
    depth.add(d, 1);
    //if(d == k) printf("node %d at depth %d\n", u + 1, k);
    for(int v : edges[u]){
        if(v != p && !removed[v]) second(v, u, d + 1);
    }
    maxdepth = max(maxdepth, d);
}

void decompose(int u){
    dfs(u, -1);
    int c = centroid(u, -1, sizes[u]);
    //printf("centroid  %d:\n", c + 1);
    maxdepth = 0;
    for(int v : edges[c]){
        if(!removed[v]){
            first(v, c, 1);
            second(v, c, 1);
        }
    }
    counter += depth.query(k1, k2);
    //printf("maxdepth : %d\n", maxdepth);
    depth.clearall(0, maxdepth + 1);
    //for(int d : depth) printf("%d ", d);
    //printf("\n");
    //printf("counter += %d\n", depth[k]);
    removed[c] = true;
    for(int v : edges[c]){
        if(!removed[v]) decompose(v);
    }
}
 
int main(){
    scanf("%d %d %d", &n, &k1, &k2);
    edges.assign(n, vector<int>());
    for(int i = 1; i < n; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    sizes.assign(n, 0);
    removed.assign(n, false);
    decompose(0);
    printf("%lld", counter);
}
