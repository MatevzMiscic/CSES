#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
vector<int> primes;

void eratosten(int n){
    vector<bool> isPrime(n + 1, true);
    for(ll i = 2; i <= n; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
}

vector<pair<int, int>> factor(int k){
    vector<pair<int, int>> pa;
    int i = 0, a = 0;
    while(k > 1){
        if(k % primes[i] == 0){
            a += 1;
            k /= primes[i];
        }else{
            if(a > 0) pa.push_back({i, a});
            a = 0;
            i += 1;
        }
    }
    if(a > 0) pa.push_back({i, a});
    return pa;
}



int main() {
    int n, p;
    scanf("%d", &n);
    vector<int> perm(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &p);
        perm[i] = p - 1;
    }
    vector<bool> vis(n, false);
    vector<int> cycles;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            int len = 0;
            for(int j = i; !vis[j]; j = perm[j]){
                vis[j] = true;
                len += 1;
            }
            cycles.push_back(len);
        }
    }
    //for(int len : cycles) printf("%d, ", len);
    //printf("\n");
    eratosten(2e5);
    //for(int i = 0; i < 15; ++i) printf("%d, ", primes[i]);
    //printf("\n");
    vector<int> lcmFactors(primes.size(), 0);
    for(int len : cycles){
        vector<pair<int, int>> pa = factor(len);
        for(auto [i, a] : pa) lcmFactors[i] = max(lcmFactors[i], a);
    }
    ll order = 1;
    for(int i = 0; i < primes.size(); ++i){
        for(int j = 0; j < lcmFactors[i]; ++j) order = (order * primes[i]) % MOD;
    }
    printf("%lld\n", order);
}