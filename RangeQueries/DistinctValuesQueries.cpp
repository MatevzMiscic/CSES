#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <unordered_map>

using namespace std;
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

int main(){
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    vector<int> arr(n + 1, 0);
    vector<int> prev(n + 1, 0);
    unordered_map<int, int> map;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &arr[i]);
        if(map[arr[i]]) prev[i] = map[arr[i]];
        map[arr[i]] = i;
    }

    //for(int a : prev) printf("%d ", a);
    //printf("\n");

    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &a, &b);
        queries.push_back({b, a, i});
    }
    vector<int> ans(q, 0);
    BIT tree(n + 1);
    sort(queries.begin(), queries.end());
    int idx = 0;
    for(auto& [b, a, i] : queries){
        //printf("[%d, %d]:  ", a, b);
        while(idx < b){
            idx++;
            if(prev[idx] > 0) tree.add(prev[idx], -1);
            tree.add(idx, 1);
        }
        ans[i] = tree.query(b) - tree.query(a - 1);
    }
    for(int a : ans) printf("%d\n", a);
}
