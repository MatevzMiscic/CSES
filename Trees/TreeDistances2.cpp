#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int n;
vector<vector<int>> edges;
vector<int> count;
vector<ll> path;
 
void first(int u, int p){
    for(int v : edges[u]){
        if(v != p){
            first(v, u);
            count[u] += count[v];
            path[u] += path[v];
        }
    }
    path[u] += count[u];
    count[u] += 1;
}

void second(int u, int p){
    for(int v : edges[u]){
        if(v != p){
            path[v] = path[u] + n - 2*count[v];
            second(v, u);
        }
    }
}

int main(){
    int a, b;
    scanf("%d", &n);
    edges.assign(n, vector<int>());
    count.assign(n, 0);
    path.assign(n, 0);
    for(int i = 0; i < n - 1; ++i){
        scanf("%d %d", &a, &b);
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    first(0, -1);
    second(0, -1);
    for(ll p : path) printf("%lld ", p);
}
