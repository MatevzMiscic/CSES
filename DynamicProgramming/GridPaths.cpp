#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    int n;
    char c;
    scanf("%d ", &n);
    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    for(int i = 1; i <= n; ++i){
        string s;
        getline(cin, s);
        for(int j = 1; j <= n; ++j){
            grid[i][j] = (s[j - 1] == '.');
        }
    }
    vector<vector<ll>> paths(n + 1, vector<ll>(n + 1, 0));
    paths[1][1] = (int)grid[1][1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == 1 && j == 1) continue;
            if(grid[i][j]){
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                if(paths[i][j] >= mod) paths[i][j] -= mod;
            }
        }
    }
    printf("%lld", paths[n][n]);
}