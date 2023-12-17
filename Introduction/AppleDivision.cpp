#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int main(){
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    ll all = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        all += arr[i];
    }
    ll diff = all;
    for(int s = 0; s < (1 << n); ++s){
        ll sum = 0;
        for(int i = 0; i < n; ++i) if(s & (1 << i)) sum += arr[i];
        diff = min(diff, abs(all - 2*sum));
    }
    printf("%lld", diff);
}
