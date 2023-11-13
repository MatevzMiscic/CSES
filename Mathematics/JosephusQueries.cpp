#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

ll n;

ll rem(ll idx, ll a, ll b, ll mod){
    ll maxidx = (n - a) / mod;
    //printf("idx = %lld, maxidx = %lld, a = %lld, b = %lld, mod = %lld\n", idx, maxidx, a, b, mod);
    if(maxidx == 0) return a + mod/2;
    if(idx <= maxidx) return idx*mod + a;
    if(maxidx*mod + a + mod/2 <= n) return rem(idx - maxidx, b - 2*mod, b + mod, 2*mod);
    return rem(idx - maxidx, b - mod, b, 2*mod);
}

int main(){
    ll q, k;
    scanf("%lld", &q);
    for(int i = 0; i < q; ++i){
        scanf("%lld %lld", &n, &k);
        printf("%lld\n", rem(k, 0, 1, 2));
    }
}
