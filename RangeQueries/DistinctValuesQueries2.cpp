#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll = long long;

struct segtree{
    int n;
    vector<int> tree;

    segtree(int n): n(n){
        tree.assign(2*n, -1);
    }
    segtree(vector<int>& arr){
        n = arr.size();
        tree.assign(2*n, -1);
        for(int i = 0; i < n; ++i) tree[n + i] = arr[i];
        for(int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
    }
    void set(int i, int x){
        i += n;
        tree[i] = x;
        for(int j = (i >> 1); j > 0; j = (j >> 1)) tree[j] = max(tree[j << 1], tree[(j << 1) + 1]);
    }
    int query(int a, int b){
        a += n; b += n;
        int m = -1;
        while(a <= b){
            if((a & 1) == 1) m = max(m, tree[a++]);
            if((b & 1) == 0) m = max(m, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return m;
    }
};

int main(){
    int n, q, t, a, b;
    scanf("%d %d", &n, &q);
    vector<int> arr(n, 0);
    vector<int> prev(n, -1);
    map<int, set<int>> indices;
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        prev[i] = (indices[arr[i]].empty() ? -1 : *indices[arr[i]].rbegin());
        indices[arr[i]].insert(i);
    }
    segtree tree(prev);
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1){
            a -= 1;
            set<int>& s = indices[arr[a]];
            s.erase(a);
            auto it = s.upper_bound(a);
            if(it != s.end()){
                prev[*it] = prev[a];
                tree.set(*it, prev[a]);
            }
            set<int>& t = indices[b];
            auto it2 = t.upper_bound(a);
            if(it2 != t.end()){
                prev[*it2] = a;
                tree.set(*it2, a);
            }
            int p = (it2 == t.begin() ? -1 : *(--it2));
            prev[a] = p;
            tree.set(a, p);
            arr[a] = b;
            t.insert(a);
        }else{
            a -= 1; b -= 1;
            int max_prev = tree.query(a, b);
            if(max_prev < a) printf("YES\n");
            else printf("NO\n");
        }
    }
}
