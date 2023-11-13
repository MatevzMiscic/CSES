#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    ll n, sum = 0;
    scanf("%lld", &n);
    for(int j = 1; j < 1e6; ++j){
        ll a = n/(j + 1) + 1, b = n/j;
        ll p = b - a + 1, q = a + b;
        if(p % 2 == 0){
            p = p >> 1;
        }else{
            q = q >> 1;
        }
        sum = (sum + j * (((p % mod)*(q % mod)) % mod)) % mod;
    }
    for(int i = 1; i <= n/1e6; ++i){
        sum = (sum + i*(n / i)) % mod;
    }
    printf("%lld", sum);
}
