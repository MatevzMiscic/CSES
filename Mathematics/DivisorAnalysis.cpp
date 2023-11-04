#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

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
    ll n, p, a;
    scanf("%lld", &n);
    ll count = 1, sum = 1, prod = 1;
    ll num = 1, root = 1, pow = 1;
    bool square = true;

    for(int i = 0; i < n; ++i){
        scanf("%lld %lld", &p, &a);
        count = (count * (a + 1)) % mod;
        sum = (sum * (((exp(p, a + 1, mod) - 1) * inv(p - 1, mod)) % mod)) % mod;
        num = (num * exp(p, a, mod)) % mod;
        if(a & 1){
            if(square){
                pow = (pow * (a + 1) / 2) % (mod - 1);
                square = false;
            }else{
                pow = (pow * (a + 1)) % (mod - 1);
            }
        }else{
            pow = (pow * (a + 1)) % (mod - 1);
            root = (root * exp(p, a / 2, mod)) % mod;
        }
    }
    if(square){
        prod = exp(root, pow, mod);
    }else{
        prod = exp(num, pow, mod);
    }
    printf("%lld %lld %lld", count, sum, prod);
}
