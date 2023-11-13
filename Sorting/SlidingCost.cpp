#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int k;
multiset<int> window;
vector<int> arr;
 
int main(){
    int n, k, x;
    scanf("%d %d", &n, &k);
    /*
    if(k == 1){
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            printf("%d ", x);
        }
        return 0;
    }
    */
    for(int i = 0; i < k; ++i){
        scanf("%d", &x);
        arr.push_back(x);
        window.insert(x);
    }
    auto it = window.begin();
    for(int i = 0; i < (k - 1) / 2; ++i) ++it;
    ll cost = 0;
    for(int y : arr) cost += abs(*it - y);
    //printf("%lld ", cost);
    printf("%lld (median %d)\n", cost, *it);
    for(int i = k; i < n; ++i){
        int delta = 0;
        scanf("%d", &x);
        auto toerase = window.lower_bound(arr[i - k]);
        int oldmedian = *it;
        if(toerase == it){
            ++it;
            delta = -1;
        }else{
            delta += 2*(arr[i - k] <= *it) - 1;
        }
        window.erase(toerase);
        cost -= abs(oldmedian - arr[i - k]);
        window.insert(x);
        cost += abs(oldmedian - x);
        delta += 2*(x >= *it) - 1;
        if(delta == 2){
            ++it;
            if(k % 2 == 0) cost -= abs(oldmedian - *it);
        }else if(delta == -2){
            --it;
        }else if(delta != 0){
            printf("delta: %d\n", delta);
        }
        arr.push_back(x);
        cost -= abs(oldmedian - *it);
        //printf("%lld ", cost);
        printf("%lld (median %d)\n", cost, *it);
    }
}