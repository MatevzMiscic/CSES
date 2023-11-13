#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> boys;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        boys.insert(i);
    }
    int i = k % boys.size();
    for(int j = 1; j < n; ++j){
        int out = *boys.find_by_order(i);
        printf("%d ", out);
        boys.erase(out);
        i = (i + k) % boys.size();
    }
    printf("%d ", *boys.find_by_order(0));
}
