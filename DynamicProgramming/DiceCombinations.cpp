#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = max(0, i - 6); j < i; ++j){
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    printf("%d", dp[n]);
}