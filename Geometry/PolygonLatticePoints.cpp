#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return abs(a);
    return gcd(b, a % b);
}

int main(){
    int n;
    ll x, y;
    scanf("%d", &n);
    vector<pair<ll, ll>> poly(n);
    for(int i = 0; i < n; ++i){
        scanf("%lld %lld", &poly[i].first, &poly[i].second);
    }
    ll A = (poly[0].first - poly[n-1].first) * (poly[0].second + poly[n-1].second);
    ll B = gcd(poly[0].first - poly[n-1].first, poly[0].second - poly[n-1].second);
    for(int i = 1; i < n; ++i){
        A += (poly[i].first - poly[i-1].first) * (poly[i].second + poly[i-1].second);
        B += gcd(poly[i].first - poly[i-1].first, poly[i].second - poly[i-1].second);
    }
    A = abs(A);
    ll I = (A - B) / 2 + 1;
    printf("%lld %lld", I, B);
}