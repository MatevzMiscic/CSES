#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;

ll inf = 1e18;

int n, m;
vector<vector<ll>> capacity;
vector<vector<int>> edges;

ll bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    deque<pair<int, ll>> q = {{s, inf}};
    while(!q.empty()){
        auto [u, flow] = q.front();
        q.pop_front();
        for(int v : edges[u]){
            if(parent[v] == -1 && capacity[u][v]){
                parent[v] = u;
                ll new_flow = min(flow, capacity[u][v]);
                if(v == t)
                    return new_flow;
                q.push_back({v, new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(int s, int t){
    ll flow = 0;
    vector<int> parent(n);
    ll deltaflow;
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

int main(){
    int u, v, c;
    scanf("%d %d", &n, &m);
    capacity.assign(n, vector<ll>(n, 0));
    edges.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &c);
        u -= 1; v -= 1;
        capacity[u][v] += c;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ll flow = maxflow(0, n - 1);
    printf("%lld\n", flow);
}