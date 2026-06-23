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
    for(int i = 0; i < k; ++i) count[arr[i]] += 1;
    set<int> mex;
    for(int i = 0; i <= k; ++i) if(count[i] == 0) mex.insert(i);
    printf("%d ", *mex.begin());
    for(int i = k; i < n; ++i){
        count[arr[i]] += 1;
        if(count[arr[i]] == 1) mex.erase(arr[i]);
        count[arr[i - k]] -= 1;
        if(count[arr[i - k]] == 0) mex.insert(arr[i - k]);
        printf("%d ", *mex.begin());
    }
}