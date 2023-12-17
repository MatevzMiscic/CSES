#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main(){
    int n, m, q, a, b, c;
    scanf("%d %d %d", &n, &m, &q);
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for(int i = 0; i < n; ++i) dist[i][i] = 0;
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        dist[a][b] = dist[b][a] = min((ll)c, dist[a][b]);
    }
    for(int w = 0; w < n; ++w){
        for(int u = 0; u < n; ++u){
            for(int v = 0; v < n; ++v){
                dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
            }
        }
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &a, &b);
        if(dist[a-1][b-1] == inf){
            printf("-1\n");
        }else{
            printf("%lld\n", dist[a-1][b-1]);
        }
    }
}