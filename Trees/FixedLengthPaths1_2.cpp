#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

int n, k, a, b;
int timer = 0;
ll counter = 0;

vector<vector<int>> edges;
vector<int> dcount;
vector<int> depth;
vector<int> sizes;
vector<int> in;
vector<int> out;
vector<int> id;

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
            for(int i = in[v]; i < out[v]; ++i) dcount[depth[id[i]]]--;
        }
    }
    if(heavy >= 0) paths(heavy, u);
    //printf("node %d, parent %d:\n", u + 1, p + 1);
    if(depth[u] + k < n){
        //printf("+%d (nodes in heavy %d on depth %d)\n", dcount[depth[u] + k], heavy + 1, k);
        counter += dcount[depth[u] + k];
    }

    dcount[depth[u]]++;
    for(int v : edges[u]){
        if(v != p && v != heavy){
            for(int i = in[v]; i < out[v]; ++i){
                int otherdepth = k - depth[id[i]] + 2*depth[u];
                if(0 <= otherdepth && otherdepth < n){
                    //printf("+%d (paths ending in %d)\n", dcount[otherdepth], id[i] + 1);
                    counter += dcount[otherdepth];
                }
            }
            for(int i = in[v]; i < out[v]; ++i) dcount[depth[id[i]]]++;
        }
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
    dcount.assign(n, 0);
    depth.assign(n, 0);
    sizes.assign(n, 0);
    in.assign(n, 0);
    out.assign(n, 0);
    id.assign(n, 0);
    dfs(0, -1, 0);
    paths(0, -1);
    printf("%lld", counter);
}
