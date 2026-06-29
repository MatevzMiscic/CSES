#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct line{
    ll k, n;
    ll eval(ll x) const{
        return k * x + n;
    }
};

constexpr ll INF = 1e18;
constexpr line zero = {0, -INF};

struct lichao{
    int n;
    vector<line> tree;
    lichao(int n) : n(n), tree(4 * n, zero) {}

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

constexpr int m = 1e5;

int main(){
    int n, t, a, b;
    scanf("%d", &n);
    lichao tree(m + 1);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &t, &a);
        if(t == 1){
            scanf("%d", &b);
            tree.add_line(0, 0, m, {a, b});
        }else{
            printf("%lld\n", tree.query(0, 0, m, a));
        }
    }
}