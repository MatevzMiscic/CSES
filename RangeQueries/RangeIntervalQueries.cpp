#include <iostream>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct BIT{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    BIT(int n): n(n){
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
};

struct query{
    int idx, sign, x, c, d;

    bool operator<(const query& other) const{
        return x < other.x;
    }
};


int main(){
    int n, q, a, b, c, d;
    scanf("%d %d", &n, &q);
    vector<int> arr(n, 0);
    vector<query> queries;
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        queries.push_back({i, 1, b, c, d + 1});
        queries.push_back({i, -1, a - 1, c, d + 1});
    }
    sort(queries.begin(), queries.end());
    int i = 0;
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ctree;
    vector<int> out(q, 0);
    for(query& q : queries){
        while(i < q.x){
            ctree.insert({arr[i], i});
            //printf("adding %d\n", arr[i]);
            i += 1;
        }
        int delta = ctree.order_of_key({q.d, -1}) - ctree.order_of_key({q.c, -1});
        out[q.idx] += q.sign * delta;
        //printf("Q(%d, %d, %d, %d, %d) = %d\n", q.idx, q.sign, q.x, q.c, q.d, delta);
    }
    for(int a : out) printf("%d\n", a);
}