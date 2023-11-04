#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, c;
    scanf("%d %d", &n, &x);
    vector<int> coins;
    for(int i = 0; i < n; ++i){
        scanf("%d", &c);
        coins.push_back(c);
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= x; ++i){
        for(int c : coins){
            if(i - c >= 0) dp[i] = dp[i] + dp[i - c];
        }
        dp[i] = dp[i] % mod;
    }
    printf("%lld", dp[x]);
}