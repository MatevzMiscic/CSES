#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>> edges;
vector<int> color;
bool flag = false;

void dfs(int u){
    for(int v : edges[u]){
        if(color[v] > 0){
            flag |= (color[v] == color[u]);
        }else{
            color[v] = 3-color[u];
            dfs(v);
        }
    }
}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    edges.assign(n, vector<int>());
    color.assign(n, 0);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int u = 0; u < n; ++u){
        if(color[u] == 0){
            color[u] = 1;
            dfs(u);
        }
    }
    if(flag){
        printf("IMPOSSIBLE");
    }else{
        for(int c : color) printf("%d ", c);
    }
}