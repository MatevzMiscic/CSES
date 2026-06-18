#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

struct ftree{
    int n, mod;
    vector<ll> arr;
    vector<ll> tree;
    ftree(int n, int mod): n(n), mod(mod){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        arr[i] = (arr[i] + x) % mod;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] = (tree[j] + x) % mod;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum = (sum + tree[j]) % mod;
        return sum;
    }
    ll query(int a, int b){
        return (query(b) - query(a-1)) % mod;
    }
};


int main(){
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    vector<int> decompress;
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
        decompress.push_back(x[i]);
    }

    // coordinate compression
    sort(decompress.begin(), decompress.end());
    decompress.erase(unique(decompress.begin(), decompress.end()), decompress.end());
    int m = decompress.size();
    unordered_map<int, int> compress;
    for(int i = 0; i < m; i++) compress[decompress[i]] = i;
    for(int i = 0; i < n; i++) x[i] = compress[x[i]];

    // dynamic programming with fenwick tree
    ftree dp(m, 1e9 + 7);
    for(int i = 0; i < n; i++){
        ll count = dp.query(x[i] - 1) + 1;
        dp.add(x[i], count);
    }
    printf("%lld", dp.query(m - 1));
}