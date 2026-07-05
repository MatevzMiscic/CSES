#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAXN = 20;
vector<ll> fact;

vector<int> unrankp(int n, ll k){
    if(n == 1) return {1};
    int head = 1 + k / fact[n - 1];
    vector<int> tail = unrankp(n - 1, k % fact[n - 1]);
    vector<int> result(n, head);
    for(int i = 0; i < n - 1; ++i){
        if(tail[i] >= head) result[i + 1] = tail[i] + 1;
        else result[i + 1] = tail[i];
    }
    return result;
}

ll rankp(int n, const vector<int>& perm){
    if(n == 1) return 0;
    int head = perm[0];
    vector<int> tail(n - 1);
    for(int i = 0; i < n - 1; ++i){
        if(perm[i + 1] > head) tail[i] = perm[i + 1] - 1;
        else tail[i] = perm[i + 1];
    }
    return (ll)(head - 1) * fact[n - 1] + rankp(n - 1, tail);
}

int main() {
    fact.assign(MAXN + 1, 1);
    for(int i = 1; i <= MAXN; ++i){
        fact[i] = fact[i - 1] * i;
    }
    int n, t, type, x;
    ll k;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%d %d", &type, &n);
        if(type == 1){
            scanf("%lld", &k);
            vector<int> perm = unrankp(n, k - 1);
            for(int a : perm) printf("%d ", a);
            printf("\n");
        }else{
            vector<int> perm(n);
            for(int j = 0; j < n; ++j) scanf("%d", &perm[j]);
            printf("%lld\n", rankp(n, perm) + 1);
        }
    }
}