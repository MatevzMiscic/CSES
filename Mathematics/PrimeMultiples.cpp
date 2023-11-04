#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int inf = 1e9;


int main(){
    ll n, k, a;
    scanf("%lld %lld", &n, &k);
    vector<ll> primes;
    for(int i = 0; i < k; ++i){
        scanf("%lld", &a);
        primes.push_back(a);
    }
    ll num = 0;
    for(int i = 1; i < (1 << k); ++i){
        int count = 0;
        ll prod = 1;
        for(int j = 0; j < k; ++j){
            if(i & (1 << j)){
                //printf("j = %d, n = %lld, prod = %lld, p = %lld\n", j, n, prod, primes[j]);
                if(primes[j] > (n / prod)){
                    prod = n + 1;
                    break;
                }
                prod *= primes[j];
                count++;
            }
        }
        num += (2*(count & 1) - 1) * (n / prod);
        //printf("pi = %d, delta = %lld\n", prod, (2*(count & 1) - 1) * (n / prod));
    }
    printf("%lld", num);
}
