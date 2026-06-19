#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;


int main(){
    int n, x;
    scanf("%d", &n);
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        freq[x ^ 123456789] += 1;
    }
    ll ans = 1, mod = 1e9 + 7;
    for(auto &[k, v] : freq){
        ans = (ans * (v + 1)) % mod;
    }
    printf("%lld\n", ans - 1);
}