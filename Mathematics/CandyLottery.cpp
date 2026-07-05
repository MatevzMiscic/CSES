#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
using ld =  long double;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    ld E = k;
    for(int j = 0; j < k; ++j){
        ld m = (ld)j / (ld)k;
        E -= pow(m, n);
    }
    ld shifted = E * 1e6;
    ll rounded = (ll)shifted;
    ld diff = shifted - rounded;
    if(abs(diff - 0.5) < 1e-6){
        if(rounded % 2 == 0) E = rounded / 1e6;
        else E = (rounded + 1) / 1e6;
    }else if(diff > 0.5) E = (rounded + 1) / 1e6;
    else E = rounded / 1e6;
    printf("%.6Lf\n", E);
}