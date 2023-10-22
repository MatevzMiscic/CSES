#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    int n, x, a;
    scanf("%d %d", &n, &x);
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        arr.push_back({a, i + 1});
    }
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    while(i < j){
        int sum = arr[i].first + arr[j].first;
        if(sum < x){
            ++i;
        }else if(sum > x){
            --j;
        }else{
            printf("%d %d", arr[i].second, arr[j].second);
            return 0;
        }
    }
    printf("IMPOSSIBLE");
}