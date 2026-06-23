#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int x, a, b, c;

ll next(ll x){
    return (a * x + b) % c;
}

int main(){
    int n, k;
    scanf("%d %d %d %d %d %d", &n, &k, &x, &a, &b, &c);
    int first = x;
    ll sum = 0;
    for(int i = 0; i < k; ++i){
        sum += first;
        first = next(first);
    }
    ll total = sum;
    int second = x;
    for(int i = k; i < n; ++i){
        sum += first - second;
        total ^= sum;
        first = next(first);
        second = next(second);
    }
    printf("%lld\n", total);
}