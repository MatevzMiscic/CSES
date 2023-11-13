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


struct segtree{
    int n;
    vector<int> arr;
    vector<int> tree;

    private:
    void build(int u, int l, int r){
        if(l == r){
            tree[u] = l;
        }else{
            int mid = (l + r) / 2;
            build(2*u + 1, l, mid);
            build(2*u + 2, mid + 1, r);
            tree[u] = tree[2*u + 1];
            if(arr[tree[2*u + 2]] > arr[tree[2*u + 1]]) tree[u] = tree[2*u + 2];
        }
    }

    void set(int u, int l, int r, int i){
        if(i < l || r < i) return;
        if(l == r) return;
        int mid = (l + r) / 2;
        set(2*u + 1, l, mid, i);
        set(2*u + 2, mid + 1, r, i);
        tree[u] = tree[2*u + 1];
        if(arr[tree[2*u + 2]] > arr[tree[2*u + 1]]) tree[u] = tree[2*u + 2];
        //printf("node: %d, l: %d, r: %d, max: %d\n", u, l, r, tree[u]);
    }

    int query(int u, int l, int r, int a, int b){
        if(r < a || b < l) return -1;
        if(a <= l && r <= b) return tree[u];
        int mid = (l + r) / 2;
        int i = query(2*u + 1, l, mid, a, b);
        int j = query(2*u + 2, mid + 1, r, a, b);
        if(i == -1) return j;
        if(j == -1) return i;
        if(arr[i] <= arr[j]) return j;
        return i;
    }

    public:
    segtree(int n): n(n){
        arr.assign(n, 0);
        tree.assign(4*n, 0);
        build(0, 0, n - 1);
    }
    segtree(vector<int>& ar){
        n = ar.size();
        arr = ar;
        tree.assign(4*n, 0);
        build(0, 0, n - 1);
    }
    void set(int i, int x){
        arr[i] = x;
        set(0, 0, n - 1, i);
    }
    int query(int a, int b){
        return query(0, 0, n - 1, a, b);
    }
};

struct segtreebu{
    int n;
    vector<int> tree;

    segtreebu(vector<int>& arr){
        n = arr.size();
        tree.assign(2*n, 0);
        for(int i = 0; i < n; ++i) tree[n + i] = arr[i];
        for(int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
    }
    void set(int i, int x){
        i += n;
        tree[i] = x;
        for(int j = (i >> 1); j > 0; j = (j >> 1)) tree[j] = max(tree[j << 1], tree[(j << 1) + 1]);
    }
    int query(int a, int b){
        a += n; b += n;
        int m = 0;
        while(a <= b){
            if((a & 1) == 1) m = max(m, tree[a++]);
            if((b & 1) == 0) m = max(m, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return m;
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

int main2(){
    vector<int> arr(10, 0);
    for(int i = 0; i < 10; ++i) scanf("%d", &arr[i]);
    segtreebu tree(arr);
    for(int u : tree.tree) printf("%d ", u);
    printf("\n");
    int a, b;
    for(int i = 0; i < 5; ++i){
        scanf("%d %d", &a, &b);
        printf("%d\n", tree.query(a, b));
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, v, a, b, t;
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
    //*/
    vector<int> arr(n, 0);
    for(int u = 0; u < n; ++u){
        arr[id[u]] = vals[u];
    }
    //segtree tree(arr);
    segtreebu tree(arr);
    for(int i = 0; i < q; ++i){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d", &a, &b);
            tree.set(id[a - 1], b);
        }else{
            scanf("%d %d", &a, &b);
            a--;
            b--;
            int pathmax = 0;
            while(top[a] != top[b]){
                if(depth[top[a]] < depth[top[b]]) swap(a, b);
                //pathmax = max(pathmax, tree.arr[tree.query(id[top[a]], id[a])]);
                pathmax = max(pathmax, tree.query(id[top[a]], id[a]));
                //printf("%d %d\n", a, b);
                //printf("max[%d, %d] = %d\n", id[top[a]], id[a], tree.query(id[top[a]], id[a]));
                a = par[top[a]];
            }
            if(depth[a] < depth[b]) swap(a, b);
            //pathmax = max(pathmax, tree.arr[tree.query(id[b], id[a])]);
            pathmax = max(pathmax, tree.query(id[b], id[a]));
            //printf("%d %d\n", a, b);
            //printf("max[%d, %d] = %d\n", id[b], id[a], tree.query(id[b], id[a]));
            printf("%d ", pathmax);
        }
    }
}
