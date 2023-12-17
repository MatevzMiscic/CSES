#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int side(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3){
    ll x = p1.second - p2.second, y = p2.first - p1.first;
    ll vx = p3.first - p1.first, vy = p3.second - p1.second;
    ll dot = x*vx + y*vy;
    if(dot > 0) return -1;
    else if(dot < 0) return 1;
    return 0;
}


int main(){
    int n, x, y;
    scanf("%d", &n);
    vector<pair<int, int>> poly(n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &poly[i].first, &poly[i].second);
    }
    sort(poly.begin(), poly.end());
    vector<int> uh = {0, 1};
    for(int i = 2; i < n; ++i){
        int j = uh.size() - 1;
        while(j >= 1 && side(poly[uh[j-1]], poly[uh[j]], poly[i]) < 0){
            //printf("%d: %d poped (uh)\n", i + 1, uh.back() + 1);
            uh.pop_back();
            j--;
        }
        uh.push_back(i);
    }
    vector<int> lh = {n-1, n-2};
    for(int i = n-3; i >= 0; --i){
        int j = lh.size() - 1;
        while(j >= 1 && side(poly[lh[j-1]], poly[lh[j]], poly[i]) < 0){
            //printf("%d: %d poped\n", i + 1, lh.back() + 1);
            lh.pop_back();
            j--;
        }
        lh.push_back(i);
    }
    uh.pop_back();
    lh.pop_back();
    printf("%d\n", uh.size() + lh.size());
    for(int i : uh) printf("%d %d\n", poly[i].first, poly[i].second);
    for(int i : lh) printf("%d %d\n", poly[i].first, poly[i].second);
}