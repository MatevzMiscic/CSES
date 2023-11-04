#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int main(){
    int n, q, b, x, k;
    scanf("%d %d", &n, &q);
    vector<int> par(n, -1);
    for(int i = 1; i < n; ++i){
        scanf("%d", &b);
        par[i] = b - 1;
    }
    vector<vector<int>> pred(n, vector<int>(20, -1));
    for(int i = 1; i < n; ++i) pred[i][0] = par[i];
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i < n; ++i){
            if(pred[i][j-1] >= 0) pred[i][j] = pred[pred[i][j-1]][j-1];
            //printf("pred[%d][%d] = %d\n", i, j, pred[i][j]);
        }
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &x, &k);
        x--;
        for(int i = 0; i < 20; ++i){
            if(k & (1 << i)){
                x = pred[x][i];
                if(x < 0) break;
            }
        }
        if(x >= 0) x++;
        printf("%d\n", x);
    }
}