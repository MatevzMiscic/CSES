#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

constexpr int inf = 2e9;

struct segtree{
    int n;
    vector<int> tree;

    segtree(int n): n(n){
        tree.assign(2*n, inf);
    }
    segtree(vector<int>& arr){
        n = arr.size();
        tree.assign(2*n, inf);
        for(int i = 0; i < n; ++i) tree[n + i] = arr[i];
        for(int i = n - 1; i > 0; --i) tree[i] = min(tree[i << 1], tree[(i << 1) + 1]);
    }
    void set(int i, int x){
        i += n;
        tree[i] = x;
        for(int j = (i >> 1); j > 0; j = (j >> 1)) tree[j] = min(tree[j << 1], tree[(j << 1) + 1]);
    }
    int query(int a, int b){
        a += n; b += n;
        int m = inf;
        while(a <= b){
            if((a & 1) == 1) m = min(m, tree[a++]);
            if((b & 1) == 0) m = min(m, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return m;
    }
};

int main(){
    int n, q, x, t, a, b;
    scanf("%d %d", &n, &q);
    segtree tree(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        tree.set(i, x);
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