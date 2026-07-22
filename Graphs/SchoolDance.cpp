#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> edges;
vector<int> match;
vector<bool> visited;

bool kuhn(int u){
    if(visited[u]) return false;
    visited[u] = true;
    for(int v : edges[u]){
        if(match[v] == -1 || kuhn(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    int u, v;
    scanf("%d %d %d", &n, &m, &k);
    edges.assign(n, vector<int>());
    match.assign(m, -1);
    visited.assign(n, false);
    for(int i = 0; i < k; ++i){
        scanf("%d %d", &u, &v);
        u -= 1; v -= 1;
        edges[u].push_back(v);
    }
    int size = 0;
    for(int u = 0; u < n; ++u){
        fill(visited.begin(), visited.end(), false);
        if(kuhn(u)) size += 1;
    }
    printf("%d\n", size);
    for(int v = 0; v < m; ++v){
        if(match[v] != -1) printf("%d %d\n", match[v] + 1, v + 1);
    }
}