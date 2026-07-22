#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> edges;

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    deque<pair<int, int>> q = {{s, 1}};
    while(!q.empty()){
        auto [u, flow] = q.front();
        q.pop_front();
        for(int v : edges[u]){
            if(parent[v] == -1 && capacity[u][v]){
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if(v == t)
                    return new_flow;
                q.push_back({v, new_flow});
            }
        }
    }
    return 0;
}

vector<pair<int, int>> mincut(int s, int t){
    vector<int> parent(n);
    int deltaflow;
    while(deltaflow = bfs(s, t, parent)){
        int v = t;
        while(v != s){
            int u = parent[v];
            capacity[u][v] -= deltaflow;
            capacity[v][u] += deltaflow;
            v = u;
        }
    }
    vector<pair<int, int>> cut;
    for(int u = 0; u < n; ++u){
        if(parent[u] == -1) continue;
        for(int v : edges[u]){
            if(parent[v] == -1) cut.push_back({u, v});
        }
    }
    return cut;
}

int main(){
    int u, v;
    scanf("%d %d", &n, &m);
    capacity.assign(n, vector<int>(n, 0));
    edges.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        u -= 1; v -= 1;
        capacity[u][v] += 1;
        capacity[v][u] += 1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<pair<int, int>> cut = mincut(0, n - 1);
    printf("%d\n", cut.size());
    for(auto [u, v] : cut){
        printf("%d %d\n", u + 1, v + 1);
    }
}