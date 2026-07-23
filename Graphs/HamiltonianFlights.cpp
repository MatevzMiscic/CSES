#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        edges[b - 1].push_back(a - 1);
    }
    vector<vector<ll>> dp(n, vector<ll>(1 << n, 0));
    dp[0][1] = 1;
    for(int mask = 1; mask < (1 << n); mask += 2){
        for(int v = 0; v < n; ++v){
            if((mask & (1 << v)) == 0) continue;
            for(int u : edges[v]){
                if(mask & (1 << u) == 0) continue;
                int umask = mask ^ (1 << v);
                dp[v][mask] += dp[u][umask];
                if(dp[v][mask] >= mod) dp[v][mask] -= mod;
            }
        }
    }
    ll ans = dp[n - 1][(1 << n) - 1];
    printf("%lld\n", ans);
}