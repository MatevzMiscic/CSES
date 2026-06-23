#include <iostream>

using namespace std;
using ll = long long;

int x, a, b, c;

ll next(ll x){
    return (a * x + b) % c;
}

int main(){
    int n, k;
    scanf("%d %d %d %d %d %d", &n, &k, &x, &a, &b, &c);
    int num = x, total = 0;
    for(int i = 0; i < n; ++i){
        int number = min(min(i + 1, n - i), k);
        //printf("number: %d\n", number);
        if((number & 1) == 1) total ^= num;
        num = next(num);
    }
    printf("%lld\n", total);
}