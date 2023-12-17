#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

struct seg{
    ll sum, sub, pre, suf;
    seg(ll sum, ll sub, ll pre, ll suf) : sum(sum), sub(sub), pre(pre), suf(suf){}
    seg(ll a){
        sum = a;
        sub = pre = suf = max<ll>(0, a);
    }
    static seg merge(const seg& a, const seg& b){
        return seg{
            a.sum + b.sum, 
            max(a.suf + b.pre, max(a.sub, b.sub)),
            max(a.pre, a.sum + b.pre), 
            max(b.suf, a.suf + b.sum)
        };
    }
};

struct segtree{
    int n;
    vector<int> arr;
    vector<seg> tree;
 
    private:
    void build(int u, int l, int r){
        if(l == r){
            tree[u] = seg(arr[l]);
        }else{
            int mid = (l + r) / 2;
            build(2*u + 1, l, mid);
            build(2*u + 2, mid + 1, r);
            tree[u] = seg::merge(tree[2*u + 1], tree[2*u + 2]);
        }
    }
 
    void set(int u, int l, int r, int i, ll x){
        if(i < l || r < i) return;
        if(l == r){
            tree[u] = seg(x);
            return;
        }
        int mid = (l + r) / 2;
        set(2*u + 1, l, mid, i, x);
        set(2*u + 2, mid + 1, r, i, x);
        tree[u] = seg::merge(tree[2*u + 1], tree[2*u + 2]);
    }
 
    seg query(int u, int l, int r, int a, int b){
        if(r < a || b < l) return -1;
        if(a <= l && r <= b) return tree[u];
        int mid = (l + r) / 2;
        return seg::merge(query(2*u + 1, l, mid, a, b), query(2*u + 2, mid + 1, r, a, b));
    }
 
    public:
    segtree(int n): n(n){
        arr.assign(n, 0);
        tree.assign(4*n, 0);
        build(0, 0, n - 1);
    }
    segtree(vector<int>& ar){
        n = ar.size();
        arr = ar;
        tree.assign(4*n, 0);
        build(0, 0, n - 1);
    }
    void set(int i, int x){
        arr[i] = x;
        set(0, 0, n - 1, i, x);
    }
    ll query(int a, int b){
        return query(0, 0, n - 1, a, b).sub;
    }
};


int main(){
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    segtree tree(arr);
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &a, &b);
        tree.set(a-1, b);
        printf("%lld\n", tree.query(0, n-1));
    }
}