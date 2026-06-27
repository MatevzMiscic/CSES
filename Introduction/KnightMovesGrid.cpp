#include <iostream>
#include <array>
#include <vector>
#include <deque>

using namespace std;

constexpr int D = 8;
array<int, D> dx = {1, 2, 2, 1, -1, -2, -2, -1};
array<int, D> dy = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
    int n;
    scanf("%d", &n);
    int inf = n*n + 1;
    vector<vector<int>> vis(n, vector<int>(n, inf));
    deque<pair<int, int>> q;
    vis[0][0] = 0;
    q.push_back({0, 0});
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop_front();
        for(int i = 0; i < D; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && vis[nx][ny] == inf){
                vis[nx][ny] = vis[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", vis[i][j]);
        }
        printf("\n");
    }
}