#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
constexpr int inf = 2e9;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    int len = 0;
    for(int a : arr){
        auto it = lower_bound(dp.begin(), dp.end(), a);
        *it = min(*it, a);
        len = max(len, (int)(it - dp.begin()));
    }
    printf("%d ", len);
}