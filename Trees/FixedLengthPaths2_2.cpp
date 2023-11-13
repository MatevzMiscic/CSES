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
int timer = 0;
ll counter = 0;

vector<vector<int>> edges;
vector<int> depth;
vector<int> sizes;
vector<int> in;
vector<int> out;
vector<int> id;
BIT dcount(2e5 + 10);

void dfs(int u, int p, int d){
    id[timer] = u;
    in[u] = timer++;
    sizes[u] = 1;
    depth[u] = d;
    for(int v : edges[u]){
        if(v != p){
            dfs(v, u, d + 1);
            sizes[u] += sizes[v];
        }
    }
    out[u] = timer;
}

void paths(int u, int p){
    int heavy = -1;
    for(int v : edges[u]){
        if(v != p){
            if(heavy < 0 || sizes[v] > sizes[heavy]) heavy = v;
        }
    }

    for(int v : edges[u]){
        if(v != p && v != heavy){
            paths(v, u);
            for(int i = in[v]; i < out[v]; ++i) dcount.add(depth[id[i]], -1);
        }
    }
    if(heavy >= 0) paths(heavy, u);
    //printf("node %d, parent %d:\n", u + 1, p + 1);
    if(depth[u] + k1 < n) counter += dcount.query(depth[u] + k1, min(depth[u] + k2, n - 1));

    dcount.add(depth[u], 1);
    for(int v : edges[u]){
        if(v != p && v != heavy){
            for(int i = in[v]; i < out[v]; ++i){
                int mindepth = max(0, k1 - depth[id[i]] + 2*depth[u]);
                int maxdepth = min(n - 1, k2 - depth[id[i]] + 2*depth[u]);
                if(mindepth < n && 0 <= maxdepth) counter += dcount.query(mindepth, maxdepth);
            }
            for(int i = in[v]; i < out[v]; ++i) dcount.add(depth[id[i]], 1);
        }
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
    depth.assign(n, 0);
    sizes.assign(n, 0);
    in.assign(n, 0);
    out.assign(n, 0);
    id.assign(n, 0);
    dfs(0, -1, 0);
    paths(0, -1);
    printf("%lld", counter);
}
