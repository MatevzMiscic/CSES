#include <iostream>
#include <array>

using namespace std;
using ll = long long;

ll INF = 1e9;

int main(){
    int n, x, y;
    scanf("%d", &n);
    ll maxDiag = -INF, minDiag = INF;
    ll maxAntiDiag = -INF, minAntiDiag = INF;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        ll diag = (ll)x + y;
        ll antiDiag = (ll)x - y;
        maxDiag = max(maxDiag, diag);
        minDiag = min(minDiag, diag);
        maxAntiDiag = max(maxAntiDiag, antiDiag);
        minAntiDiag = min(minAntiDiag, antiDiag);
        ll dist = max(maxDiag - minDiag, maxAntiDiag - minAntiDiag);
        printf("%lld\n", dist);
    }
}