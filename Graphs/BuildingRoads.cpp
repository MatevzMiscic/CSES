#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

vector<vector<int>> edges;
vector<bool> vis;

void dfs(int u){
    vis[u] = true;
    for(int v : edges[u]) if(!vis[v]) dfs(v);
}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    edges.assign(n, vector<int>());
    vis.assign(n, false);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> comp;
    for(int u = 0; u < n; ++u){
        if(!vis[u]){
            dfs(u);
            comp.push_back(u + 1);
        }
    }
    int k = comp.size();
    printf("%d\n", k - 1);
    for(int i = 1; i < k; ++i) printf("%d %d\n", comp[i-1], comp[i]);
}