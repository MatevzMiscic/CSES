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
 
int main(){
    int n, a, b, c;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d %d", &a, &b, &c);
        printf("%lld\n", exp(a, exp(b, c, mod - 1), mod));
    }
}
