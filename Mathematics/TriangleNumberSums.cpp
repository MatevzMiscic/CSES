#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

inline bool isSquare(ll n){
    ll r = (ll)(sqrt(n) + 0.5);
    return r*r == n || (r+1)*(r+1) == n || (r-1)*(r-1) == n;
}

inline bool isTriangle(ll n){
    return isSquare(8*n + 1);
}

inline bool sumOfTwoTriang(ll n){
    for(ll i = 1; i <= n; ++i){
        ll t = i * (i + 1) / 2;
        if(t > n) break;
        if(isTriangle(n - t)) return true;
    }
    return false;
}

int main(){
    int t;
    ll n;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        if(isTriangle(n)) printf("1\n");
        else if(sumOfTwoTriang(n)) printf("2\n");
        else printf("3\n");
    }
}