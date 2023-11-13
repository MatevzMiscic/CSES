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
    return exp(a, mod - 2, mod);
}


int main(){
    int m, n;
    scanf("%d %d", &n, &m);

    vector<ll> fact(m + n);
    fact[0] = 1;
    for(int i = 1; i < m + n; ++i){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll num = (fact[m + n - 1] * inv((fact[m] * fact[n-1]) % mod, mod)) % mod;
    cout << num;
}
