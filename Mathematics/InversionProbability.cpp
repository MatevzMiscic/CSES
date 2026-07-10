#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
using ll = long long;
using ld = long double;

// This file has numerical issues, so we use Python instead of C++ for this problem.
// See InversionProbability.py for the Python implementation.

int main() {
    int n;
    scanf("%d", &n);
    vector<int> r(n);
    for(int i = 0; i < n; ++i) scanf("%d", &r[i]);
    ld E = 0.0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int m = min(r[i], r[j]);
            int pairs = m * (m - 1) / 2;
            if(r[i] > r[j]) pairs += r[j] * (r[i] - r[j]);
            E += (ld)pairs / (ld)(r[i] * r[j]);
        }
    }
    ld shifted = 1e6 * E;
    ld rounded = lround(shifted);
    ld diff = shifted - floor(shifted);
    if(abs(diff - 0.5) < 1e-12){
        //printf("mid\n");
        ll floored = floor(shifted);
        if(floored % 2 == 1) rounded = floored + 1;
        else rounded = floored;
    }
    E = rounded / 1e6;
    printf("%.6f\n", (double)E);
}