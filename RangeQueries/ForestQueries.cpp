#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
 
int main(){
    int n, q, x, a, b, c, d;
    scanf("%d %d ", &n, &q);
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        string line;
        getline(cin, line);
        for(int j = 1; j <= n; ++j){
            int tree = (line[j-1] == '*');
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + tree;
        }
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a -= 1; b -= 1;
        printf("%d\n", pre[c][d] - pre[a][d] - pre[c][b] + pre[a][b]);
    }
}
