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

vector<vector<int>> edges;
vector<int> in;
vector<int> out;

int timer = 1;
void dfs(int u, int p){
    in[u] = timer++;
    for(int v : edges[u]) if(v != p) dfs(v, u);
    out[u] = timer;
}

int main(){
    int n, a, b;
    scanf("%d", &n);

    vector<int> col(n, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &col[i]);
    }

    edges.assign(n, vector<int>());
    for(int i = 1; i < n; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    in.assign(n, 0);
    out.assign(n, 0);
    dfs(0, -1);

    vector<int> arr(n + 1, 0);
    for(int i = 0; i < n; ++i) arr[in[i]] = col[i];

    vector<int> prev(n + 1, -1);
    unordered_map<int, int> map;
    for(int i = 1; i <= n; ++i){
        if(map.find(arr[i]) != map.end()) prev[i] = map[arr[i]];
        map[arr[i]] = i;
    }

    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < n; ++i){
        queries.push_back({out[i] - 1, in[i], i});
    }
    vector<int> ans(n, 0);
    BIT tree(n + 1);
    sort(queries.begin(), queries.end());
    int idx = 0;
    for(auto& [b, a, i] : queries){
        while(idx < b){
            idx++;
            if(prev[idx] > 0) tree.add(prev[idx], -1);
            tree.add(idx, 1);
        }
        ans[i] = tree.query(b) - tree.query(a - 1);
    }
    for(int a : ans) printf("%d ", a);
}
