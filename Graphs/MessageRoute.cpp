#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
 
using namespace std;
using ll = long long;

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> par(n, -1);
    par[0] = -2;
    deque<int> q = {0};
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(int v : edges[u]){
            if(par[v] == -1){
                q.push_back(v);
                par[v] = u;
            }
        }
    }
    int v = n-1;
    if(par[v] == -1){
        printf("IMPOSSIBLE");
    }else{
        vector<int> path = {v};
        while(par[v] >= 0){
            path.push_back(par[v]);
            v = par[v];
        }
        printf("%d\n", (int)path.size());
        reverse(path.begin(), path.end());
        for(int v : path) printf("%d ", v + 1);
    }

}