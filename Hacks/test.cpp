#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

int main(){
    //ll n = 3037000499L;
    ll n = 1e9;
    ll m = 10000;
    bool ok = true, flag;
    for(ll a = n-m; a <= n; ++a){
        flag = (((ll)sqrt(a*a)) == a);
        if(ok & !flag) printf("for a = %lld, sqrt(a*a) = %lld\n", a, (ll)sqrt(a*a));
        ok &= flag;
    }
    printf("ok: %d\n", (int)ok);
}