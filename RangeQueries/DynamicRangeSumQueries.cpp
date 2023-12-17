#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

struct BIT{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    BIT(int n): n(n){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        arr[i] += x;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] += x;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum += tree[j];
        return sum;
    }
    ll query(int a, int b){
        return query(b) - query(a-1);
    }
};

int main(){
    int n, q, x, t, a, b;
    scanf("%d %d", &n, &q);
    BIT tree(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        tree.add(i, x);
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1){
            tree.set(a - 1, b);
        }else{
            ll sum = tree.query(a - 1, b - 1);
            printf("%ld\n", sum);
        }
    }
}