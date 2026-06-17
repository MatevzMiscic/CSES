#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &b[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[n][m]);
    vector<int> subseq;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            subseq.push_back(a[i - 1]);
            i -= 1;
            j -= 1;
        }else{
            if(dp[i - 1][j] > dp[i][j - 1]) i -= 1;
            else j -= 1;
        }
    }
    for(auto it = subseq.rbegin(); it != subseq.rend(); ++it) printf("%d ", *it);
}