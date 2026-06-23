#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    map<int, int> count;
    for(int i = 0; i < k; ++i) count[arr[i]] += 1;
    printf("%d ", (int)count.size());
    for(int i = k; i < n; ++i){
        count[arr[i]] += 1;
        count[arr[i - k]] -= 1;
        if(count[arr[i - k]] == 0) count.erase(arr[i - k]);
        printf("%d ", (int)count.size());
    } 
}