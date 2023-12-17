#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
using ll = long long;

vector<pair<ll, ll>> points;

ll sqrt(ll n){
    ll a = 0, b = 4e9 + 1;
    while(b - a > 1){
        ll c = (a + b) / 2;
        if(c*c <= n) a = c;
        else b = c;
    }
    return a;
}

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    int n;
    scanf("%d", &n);
    points.assign(n, {0, 0});
    for(int i = 0; i < n; ++i){
        scanf("%lld %lld", &points[i].first, &points[i].second);
    }
    sort(points.begin(), points.end());
    ll d = 3e9, d2 = 9e18;
    set<pair<ll, ll>, decltype(cmp)*> tree(cmp);
    tree.insert(points[0]);
    int j = 0;
    for(int i = 1; i < points.size(); ++i){
        pair<ll, ll>& p = points[i];
        while(j < i && points[j].first < p.first - d){
            tree.erase(tree.find(points[j]));
            j++;
        }
        auto down = tree.lower_bound({-1e9, p.second - d});
        auto up = tree.upper_bound({1e9, p.second + d});
        for(auto& it = down; it != up; ++it){
            ll dist2 = (p.first - it->first)*(p.first - it->first) + (p.second - it->second)*(p.second - it->second);
            if(dist2 < d2){
                d2 = dist2;
                d = sqrt(d2);
            }
        }
        tree.insert(p);
    }
    printf("%lld", d2);
}