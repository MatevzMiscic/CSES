#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll exp(ll a, ll b, ll mod){
    if(b == 0) return 1;
    ll c = exp((a * a) % mod, b / 2, mod);
    if(b & 1) c = (c * a) % mod;
    return c;
}
 
ll inv(ll a, ll mod){
    return exp(a, mod - 2, mod);
}

int main(){
    int n, k = 0;
    scanf("%d ", &n);

    if(n % 2 == 1){
        printf("0");
        return 0;
    }

    string str;
    getline(cin, str);
    for(char c : str){
        n--;
        if(c == '(') k++;
        else if(c == ')') k--;
        else n++;
        if(k < 0){
            printf("0");
            return 0;
        }
    }
    n = (n - k) / 2;
    if(n < 0){
        printf("0");
        return 0;
    }

    vector<ll> fact(2*n + k + 1);
    fact[0] = 1;
    for(int i = 1; i <= 2*n + k; ++i){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll num = (((fact[2*n + k] * (k + 1)) % mod) * inv((((fact[n + k] * fact[n]) % mod) * (n + k + 1)) % mod, mod)) % mod;
    //printf("%d, %d\n", n, k);
    //printf("%lld, %lld\n", ((fact[2*n + k] * (k + 1)) % mod), (((fact[n + k] * fact[n]) % mod) * (n + k + 1)) % mod);
    cout << num;
}