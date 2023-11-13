#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
pair<int, int> twovals(vector<pair<int, int>> arr, int x){
    int i = 0, j = arr.size() - 1;
    while(i < j){
        int sum = arr[i].first + arr[j].first;
        if(sum < x){
            ++i;
        }else if(sum > x){
            --j;
        }else{
            return {i, j};
        }
    }
    return {-1, -1};
}
 
int main(){
    int n, x, a;
    scanf("%d %d", &n, &x);
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        arr.push_back(a);
    }
    unordered_map<int, vector<pair<int, int>>> tab;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int a = arr[i] + arr[j];
            if(a >= x) continue;
            if(tab.find(x - a) != tab.end()){
                for(auto& [k, l] : tab[x - a]){
                    if(i != k && i != l && j != k && j != l){
                        printf("%d %d %d %d", i + 1, j + 1, k + 1, l + 1);
                        return 0;
                    }
                }
            }
            tab[a].push_back({i, j});
        }
    }
    printf("IMPOSSIBLE");
}