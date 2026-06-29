#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct line{
    ll k, n;
    ll eval(ll x) const{
        return k * x + n;
    }
};

struct lichao{
    int n;
    vector<line> tree;
    lichao(int n) : n(n), tree(4 * n, {0, -1}) {}

    void add_line(int u, int l, int r, line nline){
        int m = (l + r) / 2;
        if(tree[u].eval(m) < nline.eval(m)) swap(tree[u], nline);
        if(l == r) return;
        if(tree[u].eval(l) < nline.eval(l)) add_line(2*u + 1, l, m, nline);
        else if(tree[u].eval(r) < nline.eval(r)) add_line(2*u + 2, m + 1, r, nline);
    }
    void add_segment(int u, int l, int r, int a, int b, const line& line){
        if(b < l || r < a) return;
        if(a <= l && r <= b){
            add_line(u, l, r, line);
            return;
        }
        int m = (l + r) / 2;
        add_segment(2*u + 1, l, m, a, b, line);
        add_segment(2*u + 2, m + 1, r, a, b, line);

    }
    ll query(int u, int l, int r, int x){
        if(l == r) return tree[u].eval(x);
        int m = (l + r) / 2;
        if(x <= m) return max(tree[u].eval(x), query(2*u + 1, l, m, x));
        else return max(tree[u].eval(x), query(2*u + 2, m + 1, r, x));
    }
};

int main(){
    int n, m, x1, y1, x2, y2;
    scanf("%d %d", &n, &m);
    lichao tree(m + 1);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ll k = (y2 - y1) / (x2 - x1);
        line l = {k, y1 - k * x1};
        tree.add_segment(0, 0, m, x1, x2, l);
    }
    for(int x = 0; x <= m; x++){
        printf("%lld ", tree.query(0, 0, m, x));
    }
}