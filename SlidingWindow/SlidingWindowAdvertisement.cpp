#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct line{
    ll k, n;
    ll eval(ll x){
        return k*x + n;
    }
};

const ll inf = 1e18;
const line zeroline = {0, -inf};

struct lichao{
    int n;
    vector<line> tree;

    lichao(int n): n(n), tree(4*n, zeroline){}

    void add_line(int u, int l, int r, line nline){
        int m = (l + r) / 2;
        if(tree[u].eval(m) < nline.eval(m)) swap(tree[u], nline);
        if(l == r) return;
        if(tree[u].eval(l) < nline.eval(l)) add_line(2*u + 1, l, m, nline);
        else if(tree[u].eval(r) < nline.eval(r)) add_line(2*u + 2, m+1, r, nline);
    }

    void add_line(line nline){
        add_line(0, 0, n-1, nline);
    }

    void add_segment(int u, int l, int r, int a, int b, line nline){
        if(b < l || r < a) return;
        if(a <= l && r <= b){
            add_line(u, l, r, nline);
            return;
        }
        int m = (l + r) / 2;
        add_segment(2*u + 1, l, m, a, b, nline);
        add_segment(2*u + 2, m+1, r, a, b, nline);
    }

    void add_segment(int a, int b, line nline){
        add_segment(0, 0, n-1, a, b, nline);
    }

    ll query(int u, int l, int r, int x){
        if(l == r) return tree[u].eval(x);
        int m = (l + r) / 2;
        if(x <= m) return max(tree[u].eval(x), query(2*u + 1, l, m, x));
        else return max(tree[u].eval(x), query(2*u + 2, m+1, r, x));
    }

    ll query(int x){
        return query(0, 0, n-1, x);
    }
};

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    vector<int> left(n, -1), right(n, n);
    vector<int> stack;
    for(int i = 0; i < n; ++i){
        while(!stack.empty() && arr[stack.back()] >= arr[i]) stack.pop_back();
        if(!stack.empty()) left[i] = stack.back();
        stack.push_back(i);
    }
    stack.clear();
    for(int i = n-1; i >= 0; --i){
        while(!stack.empty() && arr[stack.back()] >= arr[i]) stack.pop_back();
        if(!stack.empty()) right[i] = stack.back();
        stack.push_back(i);
    }
    lichao tree(n);
    for(int i = 0; i < n; ++i){
        //printf("idx = %d: [%d, %d] at %d\n", i, left[i] + 1, right[i] - 1, arr[i]);
        int a = left[i] - k + 2, b = min(left[i] + 1, right[i] - k);
        int c = max(left[i] + 1, right[i] - k), d = right[i] - 1;
        line l1 = {arr[i], -arr[i]*(ll)(left[i] - k + 1)}, l2 = {-arr[i], arr[i]*(ll)right[i]};
        tree.add_segment(a, b, l1);
        tree.add_segment(c, d, l2);
        //printf("segment from (%d, %d) to (%d, %d)\n", a, l1.eval(a), b, l1.eval(b));
        //printf("segment from (%d, %d) to (%d, %d)\n", c, l2.eval(c), d, l2.eval(d));
        if(c - b > 1){
            line l3 = {0, arr[i] * (ll)min(k, right[i] - left[i] - 1)};
            //printf("%d * min(%d, %d)\n", arr[i], k, right[i] - left[i] - 1);
            tree.add_segment(b + 1, c - 1, l3);
            //printf("segment from (%d, %d) to (%d, %d)\n", b + 1, l3.eval(b + 1), c - 1, l3.eval(c - 1));
        }
    }
    for(int i = 0; i <= n - k; ++i){
        ll max_area = tree.query(i);
        printf("%lld ", max_area);
    }
}