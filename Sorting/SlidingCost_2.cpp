#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> window;
vector<pair<int, int>> arr;

int main(){
    int n, k, x;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < k; ++i){
        scanf("%d", &x);
        window.insert({x, i});
        arr.push_back({x, i});
    }
    int median = window.find_by_order((k-1) / 2)->first;
    ll cost = 0;
    for(auto& y : arr) cost += abs(median - y.first);
    printf("%lld ", cost);
    for(int i = k; i < n; ++i){
        scanf("%d", &x);
        window.erase(arr[i - k]);
        window.insert({x, i});
        arr.push_back({x, i});
        cost -= abs(median - arr[i - k].first);
        cost += abs(median - x);
        int oldmedian = median;
        median = window.find_by_order((k-1) / 2)->first;
        int m;
        if(oldmedian < median){
            m = k - 2 * window.order_of_key({oldmedian + 1, -1});
        }else if(median < oldmedian){
            m = 2 * window.order_of_key({oldmedian, -1}) - k;
        }
        cost -= m * abs(median - oldmedian);
        printf("%lld ", cost);
    }
}