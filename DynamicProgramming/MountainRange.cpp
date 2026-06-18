#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Left;
vector<int> Right;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    vector<pair<int, int>> hi;
    for(int i = 0; i < n; i++){
        scanf("%d", &h[i]);
        hi.push_back({h[i], i});
    }
    vector<int> stack;
    Left.assign(n, -1);
    for(int i = 0; i < n; i++){
        while(!stack.empty() && h[stack.back()] <= h[i]) stack.pop_back();
        if(!stack.empty()) Left[i] = stack.back();
        stack.push_back(i);
    }
    stack.clear();
    Right.assign(n, -1);
    for(int i = n - 1; i >= 0; i--){
        while(!stack.empty() && h[stack.back()] <= h[i]) stack.pop_back();
        if(!stack.empty()) Right[i] = stack.back();
        stack.push_back(i);
    }
    sort(hi.begin(), hi.end());
    vector<int> dp(n, 1);
    for(auto [ht, i] : hi){
        if(Left[i] != -1) dp[Left[i]] = max(dp[Left[i]], dp[i] + 1);
        if(Right[i] != -1) dp[Right[i]] = max(dp[Right[i]], dp[i] + 1);
    }
    int ans = 0;
    for(int d : dp) ans = max(ans, d);
    printf("%d", ans);
}