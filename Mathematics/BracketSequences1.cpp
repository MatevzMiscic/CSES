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
    int n;
    scanf("%d", &n);

    if(n % 2 == 1){
        printf("0");
        return 0;
    }

    vector<ll> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; ++i){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll num = (fact[n] * inv((fact[n/2] * fact[n/2 + 1]) % mod, mod)) % mod;
    cout << num;
}
