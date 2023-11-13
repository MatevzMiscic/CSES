#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(){
    int n, a, b;
    scanf("%d", &n);
    vector<tuple<int, int, int>> begin;
    vector<tuple<int, int, int>> end;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        begin.push_back({a, -b, i});
        end.push_back({b, -a, i});
    }
    sort(begin.begin(), begin.end());
    sort(end.begin(), end.end());
    vector<int> contains(n, 0);
    vector<int> iscontained(n, 0);
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> start;
    for(auto& [b, a, i] : end){
        contains[i] = start.size() - start.order_of_key({-a, -b});
        //printf("contains[%d] = %d\n", i, contains[i]);
        start.insert({-a, -b});
        //printf("insert: %d\n", -a);
    }
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> finish;
    for(auto& [a, b, i] : begin){
        iscontained[i] = finish.size() - finish.order_of_key({-b, -a});
        //printf("iscontained[%d] = %d\n", i, iscontained[i]);
        finish.insert({-b, -a});
        //printf("insert: %d\n", -b);
    }
    for(int a : contains) printf("%d ", a);
    printf("\n");
    for(int a : iscontained) printf("%d ", a);
}
