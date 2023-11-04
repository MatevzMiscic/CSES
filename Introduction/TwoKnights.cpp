#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll ways(ll k){
    if(k >= 4){
        ll out = (k - 4)*(k - 4) * (k*k - 9);
        out += 4*(k - 4) * (k*k - 7);
        out += 4*(k - 3) * (k*k - 5);
        out += 8*(k*k - 4);
        out += 4*(k*k - 3);
        return out / 2;
    }
    if(k == 3) return 28;
    if(k == 2) return 6;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) printf("%lld\n", ways(i));
}