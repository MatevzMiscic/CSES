#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll moves = 0;
    int n, x, y = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        moves += max(0, y - x);
        //printf("%d, %d\n", max(0, y - x), max(x, y));
        y = max(x, y);
    }
    printf("%lld", moves);
}