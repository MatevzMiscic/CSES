#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

ll t;
vector<ll> machines;

bool doable(ll time){
    ll products = 0;
    for(ll m : machines){
        products += time / m;
        if(products >= t) return true;
    }
    return false;
}


int main(){
    ll n, k;
    scanf("%lld %lld", &n, &t);
    for(int i = 0; i < n; ++i){
        scanf("%lld", &k);
        machines.push_back(k);
    }
    ll a = 0;
    ll b = 1e18;
    while(b - a > 1ll){
        ll mid = (a + b) / 2;
        if(doable(mid)){
            b = mid;
        }else{
            a = mid;
        }
    }
    printf("%lld", b);
}