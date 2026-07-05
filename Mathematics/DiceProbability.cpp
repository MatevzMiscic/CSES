#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    vector<vector<double>> p(n + 1, vector<double>(b + 1, 0.0));
    p[0][0] = 1.0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= b; ++j) {
            for(int k = 1; k <= 6; ++k){
                if(j - k >= 0){
                    p[i][j] += p[i - 1][j - k] / 6.0;
                }
            }
        }
    }
    double ans = 0.0;
    for(int j = a; j <= b; ++j){
        ans += p[n][j];
    }
    printf("%.6f\n", ans);
}