#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int n;
vector<vector<pair<int, int>>> edges;
vector<ll> dist;

void dijkstra(int s){
    dist.assign(n, inf);
    dist[s] = 0;
    priority_queue<pair<ll, int>> heap;
    heap.push({0, s});
    while(!heap.empty()){
        ll d = -heap.top().first;
        int u = heap.top().second;
        heap.pop();
        //printf("%d: %d\n", u, d);
        if(dist[u] < d) continue;
        for(auto [v, l] : edges[u]){
            if(d + l < dist[v]){
                dist[v] = d + l;
                heap.push({-dist[v], v});
            }
        }
    }
}
 
int main(){
    int m, a, b, c;
    scanf("%d %d", &n, &m);
    edges.assign(n, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        edges[a-1].push_back({b-1, c});
    }
    dijkstra(0);
    for(ll d : dist) printf("%lld ", d);
}
