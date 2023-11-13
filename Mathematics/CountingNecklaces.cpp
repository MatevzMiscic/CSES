#include <iostream>
#include <vector>
#include <numeric>

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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int m, n;
    scanf("%d %d", &n, &m);
    vector<ll> pow(n + 1);
    pow[0] = 1;
    ll sum = 0;
    for(int i = 1; i <= n; ++i){
        pow[i] = (pow[i-1] * m) % mod;
        sum += pow[gcd(i, n)];
        //printf("%d:  +%lld\n", i, exp(m, gcd(i, n), mod));
    }
    sum %= mod;
    sum = (sum * inv(n, mod)) % mod;
    cout << sum;
}
