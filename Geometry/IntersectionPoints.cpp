#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct fenwick{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    fenwick(int n): n(n){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        arr[i] += x;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] += x;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum += tree[j];
        return sum;
    }
    ll query(int a, int b){
        return query(b) - query(a-1);
    }
};



constexpr int HOR_BEGIN = 0, HOR_END = 1, VER = 2;

struct event{
    int type, x, y1, y2;
    bool operator<(const event &other) const{
        if(x != other.x) return x < other.x;
        return type < other.type;
    }
};

inline int compressY(int y, const vector<int> &compress){
    return lower_bound(compress.begin(), compress.end(), y) - compress.begin();
}

int main(){
    int n, x1, y1, x2, y2;
    scanf("%d", &n);
    vector<int> compress;
    vector<event> events;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        compress.push_back(y1);
        if(x1 == x2){
            events.push_back({VER, x1, y1, y2});
            compress.push_back(y2);
        }else{
            events.push_back({HOR_BEGIN, x1, y1, y2});
            events.push_back({HOR_END, x2, y1, y2});
        }
    }
    sort(events.begin(), events.end());
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    fenwick tree(compress.size());
    ll ans = 0;
    for(event &ev: events){
        if(ev.type == HOR_BEGIN){
            tree.add(compressY(ev.y1, compress), 1);
        }else if(ev.type == HOR_END){
            tree.add(compressY(ev.y1, compress), -1);
        }else{
            ans += tree.query(compressY(ev.y1, compress), compressY(ev.y2, compress));
        }
    }
    printf("%lld\n", ans);
}