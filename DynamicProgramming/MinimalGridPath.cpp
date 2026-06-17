#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf(" %c", &grid[i][j]);
        }
    }
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string path = "";
    path += grid[0][0];
    dp[0][0] = true;
    for(int k = 1; k < 2*n - 1; ++k){
        int start = max(0, k - n + 1); // i + j == k, 0 <= i, j < n
        int end = min(k, n - 1);
        char minchar = 'Z' + 1;
        for(int i = start; i <= end; ++i){
            int j = k - i;
            if((i > 0 && dp[i - 1][j]) || (j > 0 && dp[i][j - 1])){
                dp[i][j] = true;
                minchar = min(minchar, grid[i][j]);
            }
        }
        path += minchar;
        for(int i = start; i <= end; ++i){
            int j = k - i;
            if(grid[i][j] != minchar) dp[i][j] = false;
        }
    }
    cout << path << endl;
}