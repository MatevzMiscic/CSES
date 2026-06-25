#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct update{
    ll mul, add;

    update operator+(const update &other) const{
        return {mul * other.mul, add * other.mul + other.add};
    }
};

struct segtree{
    int n;
    vector<ll> tree;
    vector<update> lazy;

    segtree(vector<ll> arr): n(arr.size()){
        tree.assign(4*n, 0);
        lazy.assign(4*n, {1, 0});
        build(0, 0, n - 1, arr);
    }
    void build(int u, int l, int r, vector<ll>& arr){
        if(l == r){
            tree[u] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(2*u + 1, l, m, arr);
        build(2*u + 2, m + 1, r, arr);
        tree[u] = tree[2*u + 1] + tree[2*u + 2];
    }
    void push(int u, int l, int r){
        int m = (l + r) / 2;
        tree[2*u + 1] = lazy[u].mul * tree[2*u + 1] + lazy[u].add * (m - l + 1);
        tree[2*u + 2] = lazy[u].mul * tree[2*u + 2] + lazy[u].add * (r - m);
        lazy[2*u + 1] = lazy[2*u + 1] + lazy[u];
        lazy[2*u + 2] = lazy[2*u + 2] + lazy[u];
        lazy[u] = {1, 0};
    }
    void rangeupdate(int u, int l, int r, int a, int b, update val){
        if(r < a || b < l) return;
        if(a <= l && r <= b){
            tree[u] = val.mul * tree[u] + val.add * (r - l + 1);
            lazy[u] = lazy[u] + val;
            return;
        }
        push(u, l, r);
        int m = (l + r) / 2;
        rangeupdate(2*u + 1, l, m, a, b, val);
        rangeupdate(2*u + 2, m + 1, r, a, b, val);
        tree[u] = tree[2*u + 1] + tree[2*u + 2];
    }
    ll query(int u, int l, int r, int a, int b){
        if(r < a || b < l) return 0;
        if(a <= l && r <= b) return tree[u];
        push(u, l, r);
        int m = (l + r) / 2;
        return query(2*u + 1, l, m, a, b) + query(2*u + 2, m + 1, r, a, b);
    }
};

int main(){
    int n, q, t, a, b, x;
    scanf("%d %d ", &n, &q);
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    segtree tree(arr);
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d", &t, &a, &b);
        a -= 1; b -= 1;
        if(t == 1){
            scanf("%d", &x);
            tree.rangeupdate(0, 0, n - 1, a, b, {1, x});
        }else if(t == 2){
            scanf("%d", &x);
            tree.rangeupdate(0, 0, n - 1, a, b, {0, x});
        }else{
            printf("%lld\n", tree.query(0, 0, n - 1, a, b));
        }

    }
}