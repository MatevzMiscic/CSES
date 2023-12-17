#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

vector<pair<ll, ll>> poly;

int side(pair<ll, ll>& p1, pair<ll, ll>& p2, pair<ll, ll>& p3){
    ll x = p1.second - p2.second, y = p2.first - p1.first;
    ll vx = p3.first - p1.first, vy = p3.second - p1.second;
    ll dot = x*vx + y*vy;
    if(dot > 0) return -1;
    else if(dot < 0) return 1;
    return 0;
}

bool onsegment(pair<ll, ll>& p1, pair<ll, ll>& p2, pair<ll, ll>& p3){
    if(side(p1, p2, p3) != 0) return false;
    if(p3.first < p1.first && p3.first < p2.first) return false;
    if(p3.first > p1.first && p3.first > p2.first) return false;
    if(p3.second < p1.second && p3.second < p2.second) return false;
    if(p3.second > p1.second && p3.second > p2.second) return false;
    return true;
}

bool boundary(pair<ll, ll>& p){
    if(onsegment(poly.back(), poly[0], p)) return true;
    for(int i = 1; i < poly.size(); ++i){
        if(onsegment(poly[i-1], poly[i], p)) return true;
    }
    return false;
}

bool inter(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll>& p3){
    if(p1.second >= p3.second && p2.second >= p3.second) return false;
    if(p1.second < p3.second && p2.second < p3.second) return false;
    if(p1.second > p2.second) swap(p1, p2);
    return side(p1, p2, p3) == 1;
}

bool inside(pair<ll, ll>& p){
    int count = 0;
    count += inter(poly.back(), poly[0], p);
    for(int i = 1; i < poly.size(); ++i){
        count += inter(poly[i-1], poly[i], p);
    }
    return count % 2 == 1;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    poly.assign(n, {0, 0});
    for(int i = 0; i < n; ++i){
        scanf("%lld %lld", &poly[i].first, &poly[i].second);
    }
    pair<ll, ll> p;
    for(int i = 0; i < m; ++i){
        scanf("%lld %lld", &p.first, &p.second);
        if(boundary(p)){
            printf("BOUNDARY\n");
        }else if(inside(p)){
            printf("INSIDE\n");
        }else{
            printf("OUTSIDE\n");
        }
    }
}