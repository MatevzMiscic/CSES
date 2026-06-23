#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long;


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    map<int, int> count;
    set<pair<int, int>> heap;
    for(int i = 0; i < k; ++i) count[arr[i]] += 1;
    for(auto [val, freq] : count) heap.insert({-freq, val});
    printf("%d ", heap.begin()->second);
    for(int i = k; i < n; ++i){
        heap.erase({-count[arr[i - k]], arr[i - k]});
        heap.erase({-count[arr[i]], arr[i]});
        count[arr[i - k]] -= 1;
        count[arr[i]] += 1;
        heap.insert({-count[arr[i - k]], arr[i - k]});
        heap.insert({-count[arr[i]], arr[i]});
        printf("%d ", heap.begin()->second);
    } 
}