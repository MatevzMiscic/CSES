#include <bits/stdc++.h>
using namespace std;
using ll = long long;
main() {
    ll n,i=0;
    cin >> n;
    array<ll,2> p[n] ;
    for (;i < n; i++) cin >> p[i][0] >> p[i][1] ;
    set<array<ll,2>> s;
    sort(p, p+n);
    ll d = LONG_MAX,j=0;
    for (i = 0; i < n; i++) {
        ll x = p[i][0], y = p[i][1];
        for (;j < i && pow(x - p[j][0], 2) > d ;j++)
            s.erase({p[j][1], p[j][0]});
        printf("sqrt(d^2) = %lld\n", (ll)sqrt(d));
        for (auto z = s.lower_bound({y - (ll)sqrt(d)});
        z != s.end() && y + sqrt(d) >= (*z)[0]; ++z){
            ll Y = (*z)[0] - y , X = (*z)[1] - x;
            d=min(d, X * X + Y * Y);
        }
        s.insert({y, x});
    }
    cout << d ;
}