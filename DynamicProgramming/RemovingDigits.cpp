#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll inf = 1e9;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for(int m = 1; m <= n; ++m){
        int j = m;
        while(j > 0){
            dp[m] = min(dp[m], dp[m - (j % 10)] + 1);
            j /= 10;
        }
    }
    printf("%d", dp[n]);
}