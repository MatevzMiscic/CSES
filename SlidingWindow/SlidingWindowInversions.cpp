#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> window;
    ll inversions = 0;
    for(int i = 0; i < k; ++i){
        int delta = i - window.order_of_key({arr[i], i});
        inversions += delta;
        window.insert({arr[i], i});
        //printf("At %d adding %d inversions. Inv: %lld\n", i, delta, inversions);
    }
    printf("%lld ", inversions);
    for(int i = k; i < n; ++i){
        inversions += k - window.order_of_key({arr[i], i});
        window.insert({arr[i], i});
        inversions -= window.order_of_key({arr[i - k], i - k});
        window.erase({arr[i - k], i - k});
        printf("%lld ", inversions);
    }
}