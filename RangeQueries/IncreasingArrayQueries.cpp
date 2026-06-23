#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>

using namespace std;
using ll = long long;

constexpr int MAX = 0;
constexpr int SUM = 1;
constexpr int OPER = 2;

struct segtree{
    int n;
    vector<int> arr;
    vector<array<ll, 3>> tree;

    segtree(vector<int>& arr): n(arr.size()), arr(arr){
        tree.assign(4*n, array<ll, 3>());
        build(0, 0, n - 1);
    }
    ll operations(int u, int l, int r, int h){
        if(h >= tree[u][MAX]) return ((ll)(r - l + 1)) * h - tree[u][SUM];
        if(l == r) return 0;
        int m = (l + r) / 2;
        if(tree[2*u + 1][MAX] <= h) 
            return ((ll)(m - l + 1)) * h - tree[2*u + 1][SUM] + operations(2*u + 2, m + 1, r, h);
        else 
            return operations(2*u + 1, l, m, h) + tree[u][OPER] - tree[2*u + 1][OPER];
    }
    void build(int u, int l, int r){
        if(l == r) tree[u] = {arr[l], arr[l], 0};
        else{
            int m = (l + r) / 2;
            build(2*u + 1, l, m);
            build(2*u + 2, m + 1, r);
            tree[u][MAX] = max(tree[2*u + 1][MAX], tree[2*u + 2][MAX]);
            tree[u][SUM] = tree[2*u + 1][SUM] + tree[2*u + 2][SUM];
            tree[u][OPER] = tree[2*u + 1][OPER] + operations(2*u + 2, m + 1, r, tree[2*u + 1][MAX]);
        }
    }
    array<ll, 3> query(int u, int l, int r, int a, int b, int h){
        if(r < a || b < l) return {-1, 0, 0};
        if(a <= l && r <= b) return {tree[u][MAX], tree[u][SUM], operations(u, l, r, h)};
        int m = (l + r) / 2;
        auto left = query(2*u + 1, l, m, a, b, h);
        auto right = query(2*u + 2, m + 1, r, a, b, max(h, (int)left[MAX]));
        return {
            max(left[MAX], right[MAX]),
            left[SUM] + right[SUM],
            left[OPER] + right[OPER],
        };
    }
};

int main(){
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    segtree tree(arr);
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &a, &b);
        printf("%lld\n", tree.query(0, 0, n - 1, a - 1, b - 1, 0)[OPER]);
    }
}
