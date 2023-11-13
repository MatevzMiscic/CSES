#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n, a, b;
    scanf("%d", &n);
    vector<tuple<int, int, int>> begin;
    vector<tuple<int, int, int>> end;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        begin.push_back({a, -b, i});
        end.push_back({b, -a, i});
    }
    sort(begin.begin(), begin.end());
    sort(end.begin(), end.end());
    vector<bool> contains(n, false);
    vector<bool> iscontained(n, false);
    int maxbegin = -1;
    for(auto& [b, a, i] : end){
        if(-a <= maxbegin){
            contains[i] = true;
        }else{
            maxbegin = -a;
        }
    }
    int maxend = -1;
    //printf("size: %d\n", begin.size());
    for(auto& [a, b, i] : begin){
        //printf("%d: [%d %d]\n", i, a, -b);
        if(-b <= maxend){
            iscontained[i] = true;
        }else{
            maxend = -b;
        }
    }
    for(int a : contains) printf("%d ", a);
    printf("\n");
    for(int a : iscontained) printf("%d ", a);
}
