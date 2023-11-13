#include <iostream>
#include <vector>

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
    ll res = exp(a, mod - 2, mod);
    //printf("inv(%lld) = %lld, %lld\n", a, res, (a*res) % mod);
    return res;
}

int main(){
    int N = 1e6;
    ll res = 1;
    vector<ll> fact(N + 1);
    fact[0] = res;
    for(int i = 1; i <= N; ++i){
        res = (res * i) % mod;
        fact[i] = res;
        //if(i < 10) printf("%d! = %lld\n", i, res);
    }
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        printf("%lld\n", (fact[a] * inv((fact[b]*fact[a-b]) % mod, mod)) % mod);
    }
}
