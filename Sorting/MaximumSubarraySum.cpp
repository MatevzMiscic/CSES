#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    int n, x;
    scanf("%d", &n);
    vector<ll> arr;
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        arr.push_back(x);
    }
    ll big = arr[0];
    vector<ll> dp = {arr[0]};
    for(int i = 1; i < n; ++i){
        ll sum = arr[i] + max(0ll, dp[i - 1]);
        //printf("sum = %lld\n", sum);
        if(sum > big) big = sum;
        dp.push_back(sum);
    }
    printf("%lld", big);
}