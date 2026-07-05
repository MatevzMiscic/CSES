#include <iostream>
#include <array>
#include <vector>

using namespace std;
using ll = long long;

ll M = 1e7;

int main() {
    int t, n;
    scanf("%d", &t);
    vector<pair<int, int>> two(M + 1, {-1, -1});
    for(int i = 0; i * i <= M; ++i){
        for(int j = 0; j * j + i * i <= M; ++j){
            int sum = i * i + j * j;
            if(sum <= M) two[sum] = {i, j};
        }
    }
    vector<array<int, 3>> twoDense;
    for(int i = 0; i <= M; ++i){
        if(two[i].first >= 0) twoDense.push_back({i, two[i].first, two[i].second});
    }
    while(t--){
        scanf("%d", &n);
        for(auto [sum, a, b] : twoDense){
            if(sum > n) break;
            if(two[n - sum].first >= 0){
                auto [c, d] = two[n - sum];
                printf("%d %d %d %d\n", c, d, a, b);
                break;
            }
        }
    }
}