#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> primes;

void eratosten(int n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= n; ++i){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

bool is_prime(ll n){
    if(n < 2) return false;
    for(int p : primes){
        if((ll)p * p > n) break;
        if(n % p == 0) return false;
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    eratosten(1e6 + 100);
    while(t--){
        ll n;
        scanf("%lld", &n);
        n += 1;
        while(!is_prime(n)) ++n;
        printf("%lld\n", n);
    }
}