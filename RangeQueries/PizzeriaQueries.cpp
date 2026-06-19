#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <algorithm>
 
using namespace std;

int inf = 2e9;

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
    int n, q, t, k, x;
    scanf("%d %d", &n, &q);
    vector<int> L(n), R(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        L[i] = x - i;
        R[i] = x + i;
    }
    segtree ltree(L), rtree(R);
    for(int i = 0; i < q; ++i){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d", &k, &x);
            k -= 1;
            ltree.set(k, x - k);
            rtree.set(k, x + k);
        }else{
            scanf("%d", &k);
            k -= 1;
            int l = ltree.query(0, k) + k;
            int r = rtree.query(k, n - 1) - k;
            printf("%d\n", min(l, r));
        }
    }
}
