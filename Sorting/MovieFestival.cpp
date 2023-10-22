#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    int n, a, b;
    scanf("%d", &n);
    vector<pair<int, int>> movies;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        movies.push_back({b, a});
    }
    sort(movies.begin(), movies.end());
    vector<int> ending = {(int)2e9};
    for(auto pair : movies){
        auto it = upper_bound(ending.begin(), ending.end(), pair.second);
        if(pair.first < *it) *it = pair.first;
        if(ending.back() != (int)2e9) ending.push_back((int)2e9);
    }
    printf("%d", ending.size() - 1);
}