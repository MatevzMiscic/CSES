#include <iostream>
#include <vector>
 
using namespace std;


struct segtree{
    int n;
    vector<int> arr;
    vector<pair<int, int>> tree;
 
    segtree(int n): n(n){
        arr.assign(n, 0);
        tree.assign(4*n, {0, 0});
    }
    segtree(vector<int>& arr): n(arr.size()), arr(arr){
        tree.assign(4*n, {0, 0});
        build(0, 0, n - 1);
    }
    void build(int u, int l, int r){
        if(l == r){
            tree[u] = {arr[l], 1};
        }else{
            int mid = (l + r) / 2;
            build(2*u + 1, l, mid);
            build(2*u + 2, mid + 1, r);
            int m = max(tree[2*u + 1].first, tree[2*u + 2].first);
            int v = tree[2*u + 1].second + visible(2*u + 2, mid + 1, r, tree[2*u + 1].first);
            tree[u] = {m, v};
        }
        //printf("[%d, %d] = (%d, %d)\n", l, r, tree[u].first, tree[u].second);
    }
    int visible(int u, int l, int r, int h){
        if(tree[u].first <= h) return 0;
        if(l == r) return 1;
        int mid = (l + r) / 2;
        if(tree[2*u + 1].first <= h) return visible(2*u + 2, mid + 1, r, h);
        return visible(2*u + 1, l, mid, h) + (tree[u].second - tree[2*u + 1].second);
    }
    pair<int, int> query(int u, int l, int r, int a, int b, int h){
        if(r < a || l > b) return {0, 0};
        if(a <= l && r <= b) return {tree[u].first, visible(u, l, r, h)};
        int mid = (l + r) / 2;
        pair<int, int> left = query(2*u + 1, l, mid, a, b, h);
        pair<int, int> right = query(2*u + 2, mid + 1, r, a, b, max(h, left.first));
        pair<int, int> out = {max(left.first, right.first), left.second + right.second};
        //printf("Q [%d, %d] = (%d, %d)\n", max(a, l), min(b, r), out.first, out.second);
        return out;
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
        int ans = tree.query(0, 0, n - 1, a - 1, b - 1, 0).second;
        printf("%d\n", ans);
    }
}
