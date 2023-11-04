#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

vector<int> depth;
vector<vector<int>> pred;
vector<vector<int>> edges;

void dfs(int u, int p){
    if(p >= 0){
        depth[u] = depth[p] + 1;
        pred[u][0] = p;
    }
    for(int v : edges[u]){
        if(v != p) dfs(v, u);
    }
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    int k = depth[x] - depth[y];
    for(int i = 0; i < 20; ++i){
        if(k & (1 << i)){
            x = pred[x][i];
            if(x < 0) break;
        }
    }
    if(x == y){
        return x;
    }
    for(int i = 19; i >= 0; --i){
        if(pred[x][i] != pred[y][i]){
            x = pred[x][i];
            y = pred[y][i];
        }
    }
    return pred[x][0];
}

int main(){
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    edges.assign(n, vector<int>());
    for(int i = 1; i < n; ++i){
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    depth.assign(n, 0);
    pred.assign(n, vector<int>(20, -1));
    dfs(0, -1);

    for(int j = 1; j < 20; ++j){
        for(int i = 1; i < n; ++i){
            if(pred[i][j-1] >= 0) pred[i][j] = pred[pred[i][j-1]][j-1];
        }
    }

    for(int l = 0; l < q; ++l){
        scanf("%d %d", &a, &b);
        a--;
        b--;
        printf("%d\n", depth[a] + depth[b] - 2*depth[lca(a, b)]);
    }
}