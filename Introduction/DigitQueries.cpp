#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

int main(){
    int n;
    scanf("%d", &n);
    ll k;
    for(int i = 0; i < n; ++i){
        scanf("%lld", &k);
        ll d = 1, num = 9;
        while(num*d < k){
            k -= num*d;
            d++;
            num *= 10;
        }
        //printf("k = %lld, digit = %lld\n", k, d);
        ll number = num / 9 + (k - 1) / d;
        ll digit = d - (k - 1) % d - 1;
        //printf("number = %lld, digit = %lld\n", number, digit);
        for(int j = 0; j < digit; ++j) number /= 10;
        printf("%d\n", (int)(number % 10));
    }
}
