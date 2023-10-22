#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    int n, a, b, x;
    scanf("%d %d %d", &n, &a, &b);
    vector<ll> arr;
    vector<ll> presum = {0};
    vector<ll> min(n + 1, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        arr.push_back(x);
        presum.push_back(presum[i] + x);
    }
    
    multiset<ll> set;
    for(int i = a; i <= n; ++i){
        if(i - b - 1 >= 0) set.erase(set.find(presum[i - b - 1]));
        set.insert(presum[i - a]);
        min[i] = *set.begin();
        //printf("i = %d, min = %lld\n", i, min[i]);
    }

    ll big = (ll)(-1e15);
    for(int i = a; i <= n; ++i){
        ll sum = presum[i] - min[i];
        if(sum > big) big = sum;
    }
    printf("%lld", big);
}