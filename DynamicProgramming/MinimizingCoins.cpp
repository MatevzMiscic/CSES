#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

int inf = 1e6 + 1;

int main(){
    int n, x, c;
    scanf("%d %d", &n, &x);
    vector<int> coins;
    for(int i = 0; i < n; ++i){
        scanf("%d", &c);
        coins.push_back(c);
    }
    vector<int> dp(x + 1, inf);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i){
        for(int c : coins){
            if(i - c >= 0) dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    if(dp[x] == inf){
        printf("-1");
    }else{
        printf("%d", dp[x]);
    }
}