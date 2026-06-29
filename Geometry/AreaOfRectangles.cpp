#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


struct segtree{
    vector<pair<int, int>> tree; // covered, length
    segtree(int n) : tree(4 * n, {0, 0}) {}
    void add(int u, int l, int r, int a, int b, int d){
        if(b < l || r < a) return;
        if(a <= l && r <= b){
            tree[u].first += d;
        }else{
            int m = (l + r) / 2;
            add(2*u + 1, l, m, a, b, d);
            add(2*u + 2, m + 1, r, a, b, d);
        }
        if(tree[u].first > 0) tree[u].second = r - l + 1;
        else if(l == r) tree[u].second = 0;
        else tree[u].second = tree[2*u + 1].second + tree[2*u + 2].second;
    }
};

struct event{
    int x, y1, y2, add;
    event(int x, int y1, int y2, int add) : x(x), y1(y1), y2(y2), add(add) {}
    bool operator<(const event& other) const{
        return x < other.x;
    }
};

constexpr int m = 1e6;

int main(){
    int n, x1, y1, x2, y2;
    scanf("%d", &n);
    vector<event> events;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        y1 += m; y2 += m;
        events.push_back(event(x1, y1, y2, 1));
        events.push_back(event(x2, y1, y2, -1));
    }
    sort(events.begin(), events.end());
    segtree tree(2*m + 1);
    ll ans = 0;
    for(int i = 0; i < events.size(); i++){
        if(i > 0) ans += (ll)(events[i].x - events[i - 1].x) * tree.tree[0].second;
        tree.add(0, 0, 2*m, events[i].y1, events[i].y2 - 1, events[i].add);
    }
    printf("%lld\n", ans);
}