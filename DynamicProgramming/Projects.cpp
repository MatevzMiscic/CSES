#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int inf = 2e9;

int main(){
    int n, a, b, p;
    scanf("%d", &n);
    vector<tuple<int, int, int>> proj;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        scanf("%d %d %d", &a, &b, &p);
        proj.push_back({a, b, p});
        arr.push_back(a);
        arr.push_back(b);
    }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    unordered_map<int, int> reidx;
    int m = arr.size();
    for(int i = 0; i < m; ++i){
        reidx[arr[i]] = i;
    }
    for(tuple<int, int, int>& tup : proj){
        get<0>(tup) = reidx[get<0>(tup)];
        get<1>(tup) = reidx[get<1>(tup)];
    }
    vector<int> dp();


    printf("%d ", len);
}