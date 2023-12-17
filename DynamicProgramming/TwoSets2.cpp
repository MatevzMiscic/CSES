#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll exp(ll a, ll b, ll mod){
    if(b == 0) return 1;
    ll c = exp((a * a) % mod, b / 2, mod);
    if(b & 1) c = (c * a) % mod;
    return c;
}

ll inv(ll a, ll mod){
    return exp(a, mod - 2, mod);
}

int main(){
    int n;
    scanf("%d", &n);
    int N = n*(n + 1) / 2;
    if(N % 2 == 1){
        printf("0");
        return 0;
    }
    N /= 2;
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for(int a = 1; a <= n; ++a){
        for(int i = N; i >= a; --i){
            dp[i] += dp[i - a];
            if(dp[i] >= mod) dp[i] -= mod;
        }
    }
    printf("%d\n", (dp[N] * inv(2, mod)) % mod);
}