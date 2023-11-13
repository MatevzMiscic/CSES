#include <cstdio>
#include <vector>
#include <unordered_map>
 
using namespace std;
using ll = long long;
 
int n, k, a, b, maxdepth;
ll counter = 0;
vector<vector<int>> edges;
vector<int> sizes;
vector<bool> removed;
vector<int> depth;
 
 
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
    if(d > k) return;
    //printf("%d: +%d\n", u + 1, depth[k - d]);
    counter += depth[k - d];
    for(int v : edges[u]){
        if(v != p && !removed[v]) first(v, u, d + 1);
    }
}
 
void second(int u, int p, int d){
    if(d > k) return;
    depth[d] += 1;
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
    //depth.assign(k + 1, 0);
    maxdepth = 0;
    for(int v : edges[c]){
        if(!removed[v]){
            first(v, c, 1);
            second(v, c, 1);
        }
    }
    counter += depth[k];
    //printf("maxdepth : %d\n", maxdepth);
    fill(depth.begin(), depth.begin() + maxdepth + 1, 0);
    //for(int d : depth) printf("%d ", d);
    //printf("\n");
    //printf("counter += %d\n", depth[k]);
    removed[c] = true;
    for(int v : edges[c]){
        if(!removed[v]) decompose(v);
    }
}
 
int main(){
    scanf("%d %d", &n, &k);
    edges.assign(n, vector<int>());
    for(int i = 1; i < n; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    sizes.assign(n, 0);
    removed.assign(n, false);
    depth.assign(k + 1, 0);
    decompose(0);
    printf("%lld", counter);
}
