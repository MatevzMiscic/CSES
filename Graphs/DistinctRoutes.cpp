#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
vector<vector<int>> initcapacity;
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

int maxflow(int s, int t){
    int flow = 0;
    vector<int> parent(n);
    int deltaflow;
    while(deltaflow = bfs(s, t, parent)){
        flow += deltaflow;
        int v = t;
        while(v != s){
            int u = parent[v];
            capacity[u][v] -= deltaflow;
            capacity[v][u] += deltaflow;
            v = u;
        }
    }
    return flow;
}

void getpath(int u, int t, vector<int>& path){
    path.push_back(u);
    if(u == t) return;
    for(int v : edges[u]){
        if(initcapacity[u][v] == 1 && capacity[u][v] == 0){
            capacity[u][v] -= 1;
            capacity[v][u] += 1;
            getpath(v, t, path);
            return;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    capacity.assign(n, vector<int>(n, 0));
    edges.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u -= 1; v -= 1;
        capacity[u][v] += 1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    initcapacity = capacity;
    int flow = maxflow(0, n - 1);
    printf("%d\n", flow);
    for(int i = 0; i < flow; ++i){
        vector<int> path;
        getpath(0, n - 1, path);
        printf("%d\n", (int)path.size());
        for(int u : path) printf("%d ", u + 1);
        printf("\n");
    }
}