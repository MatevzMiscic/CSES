#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct line{
    int k, n;
    bool operator<(const line &other) const{
        if(k != other.k) return k < other.k;
        return n > other.n;
    }
    ll eval(ll x) const{
        return (ll)k * x + n;
    }

    static double intersect(const line &a, const line &b){
        return (double)(b.n - a.n) / (a.k - b.k);
    }
};

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<line> lines(n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        lines[i] = {(b - a) / m, a};
    }
    sort(lines.begin(), lines.end());
    vector<line> filtered;
    for(line l : lines){
        if(filtered.empty() || filtered.back().k < l.k) filtered.push_back(l);
    }
    vector<line> envelope;
    for(line l : filtered){
        while(envelope.size() >= 2 && line::intersect(envelope[envelope.size()-2], envelope.back()) >= line::intersect(envelope.back(), l)) envelope.pop_back();
        envelope.push_back(l);
    }
    //for(line l : envelope) printf("line: y = %d * x + %d\n", l.k, l.n);
    int i = 0;
    for(int x = 0; x <= m; x++){
        while(i + 1 < envelope.size() && envelope[i].eval(x) < envelope[i + 1].eval(x)) i += 1;
        printf("%lld ", envelope[i].eval(x));
    }
}