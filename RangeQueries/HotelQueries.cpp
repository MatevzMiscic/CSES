#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

struct segtree{
    int n;
    vector<int> tree;

    segtree(int n): n(n){
        tree.assign(2*n, 0);
    }
    segtree(vector<int>& arr){
        n = arr.size();
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
        if(tree.query(0, n-1) < x){
            printf("0 ");
            printf("\n");
            continue;
        }
        int a = -1, b = n;
        while(b - a > 1){
            int m = (a + b) / 2;
            if(tree.query(0, m) < x){
                a = m;
            }else{
                b = m;
            }
        }
        printf("%d ", b + 1);
        tree.add(b, -x);
    }
}