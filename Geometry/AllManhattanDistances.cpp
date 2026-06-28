#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using lll = __int128;

void print128(lll x) {
    if (x < 0){
        putchar('-');
        x = -x;
    }
    if (x > 9) print128(x / 10);
    putchar('0' + (int)(x % 10));
}

int main(){
    int n;
    scanf("%d", &n);
    vector<ll> xs(n), ys(n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &xs[i], &ys[i]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    lll dist = 0;
    lll sumx = xs[0], sumy = ys[0];
    for(int i = 1; i < n; i++){
        dist += (lll)i * xs[i] - sumx;
        sumx += xs[i];
        dist += (lll)i * ys[i] - sumy;
        sumy += ys[i];
    }
    print128(dist);
}