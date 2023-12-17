#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <algorithm>
 
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
    ll query(int a, int b){
        return query(b) - query(a-1);
    }
};

unordered_map<int, int> compress(vector<int>& vals){
    sort(vals.begin(), vals.end());
    auto last = unique(vals.begin(), vals.end());
    vals.erase(last, vals.end());
    unordered_map<int, int> tocompressed;
    for(int i = 0; i < vals.size(); ++i){
        tocompressed[vals[i]] = i;
    }
    return tocompressed;
}

int main(){
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    vector<int> vals(n);
    vector<int> arr(n);
    vector<array<int, 3>> queries(q);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        vals[i] = arr[i];
    }
    for(int i = 0; i < q; ++i){
        char t;
        scanf(" %c %d %d", &t, &a, &b);
        if(t == '!'){
            queries[i] = {0, a-1, b};
        }else{
            queries[i] = {1, a, b};
            vals.push_back(a);
        }
        vals.push_back(b);
    }
    vector<int> salary(n);
    unordered_map<int, int> tocompressed = compress(vals);
    int M = vals.size();
    //printf("%d values\n", M);
    BIT tree(M);
    for(int i = 0; i < n; ++i){
        arr[i] = tocompressed[arr[i]];
        tree.add(arr[i], 1);
    }
    for(array<int, 3>& query : queries){
        if(query[0] == 0){
            tree.add(arr[query[1]], -1);
            arr[query[1]] = tocompressed[query[2]];
            tree.add(arr[query[1]], 1);
        }else{
            printf("%lld\n", tree.query(tocompressed[query[1]], tocompressed[query[2]]));
        }
    }
}