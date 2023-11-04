#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

ll inf = 1e9;
ll mod = 1e9 + 7;

ll exp(ll a, ll b, ll mod){
    if(b == 0) return 1;
    ll c = exp((a * a) % mod, b / 2, mod);
    if(b & 1) c = (c * a) % mod;
    return c;
}


int main(){
    ll n;
    scanf("%lld", &n);
    vector<ll> p;
    vector<int> a;
    vector<int> primes(1e6 + 1, inf);
    for(int i = 2; i <= 1e6; ++i){
        if(primes[i] == inf){
            int count = 0;
            while(n % i == 0){
                n /= i;
                count++;
            }
            if(count > 0){
                p.push_back(i);
                a.push_back(count);
                //printf("%d, %d, %d\n", i, count, n);
            }
            for(int j = 2*i; j <= 1e6; j += i){
                primes[j] = min(primes[j], i);
            }
        }
    }
    if(n > 1){
        p.push_back(n);
        a.push_back(1);
    }

    ll sum = 1;
    for(int i = 0; i < p.size(); ++i){
        //printf("%lld, %d\n", p[i], a[i]);
        sum *= (exp(p[i], a[i] + 1, mod) - 1) / (p[i] - 1);
    }

    printf("%lld", sum);
}
