#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ll n;
    scanf("%lld", &n);
    printf("%lld ", n);
    while(n > 1){
        if(n % 2 == 0){
            n = n / 2L;
        }else{
            n = 3L * n + 1;
        }
        printf("%ld ", n);
    }
}