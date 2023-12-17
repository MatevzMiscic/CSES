#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
tree_order_statistics_node_update> arr;

int main(){
    int n, x, idx;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        arr.insert({i, x});
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &idx);
        auto it = arr.find_by_order(idx-1);
        printf("%d ", it->second);
        arr.erase(it);
    }
}