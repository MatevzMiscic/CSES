#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n, x;
    scanf("%d", &n);
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        arr[i] = x;
    }
    sort(arr.begin(), arr.end());
    auto it = unique(arr.begin(), arr.end());
    int size = it - arr.begin();
    printf("%d", size);
}