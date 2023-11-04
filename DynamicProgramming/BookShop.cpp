#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

int inf = 1e6 + 1;

int main(){
    int n, x, h, s;
    scanf("%d %d", &n, &x);
    vector<int> prices;
    vector<int> pages;
    for(int i = 0; i < n; ++i){
        scanf("%d", &h);
        prices.push_back(h);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &s);
        pages.push_back(s);
    }
    int best = 0;
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for(int j = prices[0]; j <= x; ++j){
        dp[0][j] = pages[0];
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= x; ++j){
            dp[i][j] = dp[i - 1][j];
            if(prices[i] <= j) dp[i][j] = max(dp[i][j], pages[i] + dp[i - 1][j - prices[i]]);
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            best = max(best, dp[i][j]);
        }
    }
    printf("%d", best);
}