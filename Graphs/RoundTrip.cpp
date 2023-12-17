#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>> edges;
vector<int> par;
int top = -1, bottom = -1;

void dfs(int u, int p){
    //printf("u = %d, p = %d\n", u+1, p+1);
    par[u] = p;
    for(int v : edges[u]){
        if(v == p) continue;
        if(par[v] == -1){
            dfs(v, u);
            if(top >= 0) return;
        }else{
            top = v;
            bottom = u;
            //printf("top = %d, bottom = %d\n", v+1, u+1);
            return;
        }
    }
}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    edges.assign(n, vector<int>());
    par.assign(n, -1);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int u = 0; u < n; ++u){
        if(par[u] == -1) dfs(u, u);
        if(top >= 0) break;
    }
    if(top == -1){
        printf("IMPOSSIBLE");
        return 0;
    }
    int v = bottom, k = 2;
    while(v != top){
        k++;
        v = par[v];
    }
    printf("%d\n", k);
    v = bottom;
    while(v != top){
        printf("%d ", v + 1);
        v = par[v];
    }
    printf("%d %d", top + 1, bottom + 1);
}