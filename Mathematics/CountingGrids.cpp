#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll mod = 1e9 + 7;

ll exp(ll a, ll b, ll mod){
    if(b == 0) return 1;
    ll c = exp((a * a) % mod, b / 2, mod);
    if(b & 1) c = (c * a) % mod;
    return c;
}
 
ll inv(ll a, ll mod){
    return exp(a, mod - 2, mod);
}

int main(){
    ll n;
    scanf("%lld", &n);
    ll sum = exp(2, n*n, mod);
    if(n % 2 == 0){
        sum += exp(2, n*n / 2, mod) + 2 * exp(2, n*n / 4, mod);
    }else{
        sum += exp(2, (n*n - 1) / 2 + 1, mod) + 2 * exp(2, (n*n - 1) / 4 + 1, mod);
    }
    sum = ((sum % mod) * inv(4, mod)) % mod;
    printf("%lld", sum);
}
