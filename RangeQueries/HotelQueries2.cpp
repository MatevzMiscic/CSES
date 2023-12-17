#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

struct segtree{
    int n;
    vector<int> tree;

    segtree(int size){
        n = 1 << (__builtin_clz(1) - __builtin_clz(2*size - 1));
        tree.assign(2*n, 0);
    }
    segtree(vector<int>& arr){
        n = 1 << (__builtin_clz(1) - __builtin_clz(2*arr.size() - 1));
        tree.assign(2*n, 0);
        for(int i = 0; i < n; ++i) tree[n + i] = arr[i];
        for(int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
    }
    void set(int i, int x){
        i += n;
        tree[i] = x;
        for(int j = (i >> 1); j > 0; j = (j >> 1)) tree[j] = max(tree[j << 1], tree[(j << 1) + 1]);
    }
    void add(int i, int x){
        i += n;
        tree[i] += x;
        for(int j = (i >> 1); j > 0; j = (j >> 1)) tree[j] = max(tree[j << 1], tree[(j << 1) + 1]);
    }
    int query(int a, int b){
        a += n; b += n;
        int m = 0;
        while(a <= b){
            if((a & 1) == 1) m = max(m, tree[a++]);
            if((b & 1) == 0) m = max(m, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return m;
    }
    int firstgeq(int x){
        int i = 1;
        while(i < n){
            if(tree[2*i] >= x) i = 2*i;
            else i = 2*i + 1;
        }
        return i - n;
    }

};

int main(){
    int n, m, x;
    scanf("%d %d", &n, &m);
    segtree tree(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        tree.set(i, x);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &x);
        if(tree.tree[1] < x){
            printf("0 ");
            continue;
        }
        int b = tree.firstgeq(x);
        printf("%d ", b + 1);
        tree.add(b, -x);
    }
}