#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
vector<int> depth;
vector<vector<int>> child;
 
void dfs(int u, int d){
    depth[u] = d;
    for(int v : child[u]) dfs(v, d + 1);
}
 
int main(){
    int n, q, b, x, y;
    scanf("%d %d", &n, &q);
    vector<int> par(n, -1);
    child.assign(n, vector<int>());
    for(int i = 1; i < n; ++i){
        scanf("%d", &b);
        b--;
        par[i] = b;
        child[b].push_back(i);
    }
    depth.assign(n, 0);
    dfs(0, 0);
 
    vector<vector<int>> pred(n, vector<int>(20, -1));
    for(int i = 1; i < n; ++i) pred[i][0] = par[i];
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i < n; ++i){
            if(pred[i][j-1] >= 0) pred[i][j] = pred[pred[i][j-1]][j-1];
        }
    }
    for(int l = 0; l < q; ++l){
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if(depth[x] < depth[y]) swap(x, y);
        int k = depth[x] - depth[y];
        for(int i = 0; i < 20; ++i){
            if(k & (1 << i)){
                x = pred[x][i];
                if(x < 0) break;
            }
        }
        if(x == y){
            printf("%d\n", x + 1);
            continue;
        }
        for(int i = 19; i >= 0; --i){
            if(pred[x][i] != pred[y][i]){
                x = pred[x][i];
                y = pred[y][i];
            }
        }
        printf("%d\n", par[x] + 1);
    }
}
