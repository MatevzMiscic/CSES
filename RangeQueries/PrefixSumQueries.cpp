#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

struct segtree{
    const ll unit = -1e18;
    const ll def = 0;
    int n;
    vector<ll> arr;
    vector<ll> tree;
    vector<ll> lazy;
 
    private:

    void push(int u){
        tree[2*u + 1] += lazy[u];
        lazy[2*u + 1] += lazy[u];
        tree[2*u + 2] += lazy[u];
        lazy[2*u + 2] += lazy[u];
        lazy[u] = 0;
    }

    void build(int u, int l, int r){
        if(l == r){
            tree[u] = arr[l];
        }else{
            int mid = (l + r) / 2;
            build(2*u + 1, l, mid);
            build(2*u + 2, mid + 1, r);
            tree[u] = max(tree[2*u + 1], tree[2*u + 2]);
        }
    }
 
    void add(int u, int l, int r, int a, int b, ll x){
        if(b < l || r < a) return;
        if(a <= l && r <= b){
            tree[u] += x;
            lazy[u] += x;
            return;
        }
        push(u);
        int mid = (l + r) / 2;
        add(2*u + 1, l, mid, a, b, x);
        add(2*u + 2, mid + 1, r, a, b, x);
        tree[u] = max(tree[2*u + 1], tree[2*u + 2]);
        //printf("node: %d, [%d, %d], max: %lld + %lld\n", u, l, r, tree[u], lazy[u]);
    }
 
    ll query(int u, int l, int r, int a, int b){
        if(r < a || b < l) return unit;
        if(a <= l && r <= b) return tree[u];
        push(u);
        int mid = (l + r) / 2;
        return max(query(2*u + 1, l, mid, a, b), query(2*u + 2, mid + 1, r, a, b));
    }
 
    public:
    segtree(int n): n(n){
        arr.assign(n, 0);
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(0, 0, n - 1);
    }
    segtree(vector<ll>& ar){
        n = ar.size();
        arr = ar;
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(0, 0, n - 1);
    }
    void add(int a, int b, ll x){
        add(0, 0, n - 1, a, b, x);
    }
    ll query(int a, int b){
        return query(0, 0, n - 1, a, b);
    }
    void print(){
        for(ll t : tree) printf("%lld ", t);
        printf("\n");
        for(ll l : lazy) printf("%lld ", l);
        printf("\n");
    }
};


int main(){
    int n, q, t, a, b;
    scanf("%d %d", &n, &q);
    ll sum = 0;
    vector<ll> arr(n);
    vector<ll> pre(n);
    for(int i = 0; i < n; ++i){
        scanf("%lld", &arr[i]);
        sum += arr[i];
        pre[i] = sum;
    }
    segtree tree(pre);
    //tree.print();
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1){
            tree.add(a-1, n-1, b - arr[a-1]);
            arr[a-1] = b;
            //tree.print();
        }else{
            ll prefix = 0;
            if(a >= 2) prefix = tree.query(a-2, a-2);
            //printf("%lld, %lld\n", prefix, tree.query(a-1, b-1));
            printf("%lld\n", max((ll)0, tree.query(a-1, b-1) - prefix));
        }
    }
}