#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
 
using namespace std;
using ll = long long;

constexpr int inf = 1e7;

int n, m;
vector<string> graph;
 
bool inbound(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && graph[x][y] == '.';
}
 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char dir[4] = {'D', 'L', 'U', 'R'};
 
int main(){
    pair<int, int> A, B = {-1, -1};
    scanf("%d %d ", &n, &m);
    graph.assign(n, "");
    deque<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, inf));
    for(int i = 0; i < n; ++i){
        getline(cin, graph[i]);
        for(int j = 0; j < m; ++j){
            if(graph[i][j] == 'A'){
                graph[i][j] = '.';
                A = {i, j};
            }else if(graph[i][j] == 'M'){
                graph[i][j] = '.';
                q.push_back({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop_front();
        for(int i = 0; i < 4; ++i){
            int X = x + dx[i], Y = y + dy[i];
            if(inbound(X, Y) && dist[X][Y] == inf){
                q.push_back({X, Y});
                dist[X][Y] = dist[x][y] + 1;
            }
        }
    }
    /*
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    */
    vector<vector<pair<int, int>>> pardist(n, vector<pair<int, int>>(m, {-1, -1}));
    pardist[A.first][A.second] = {-1, 0};
    q = {A};
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop_front();
        if(x == 0 || x == n-1 || y == 0 || y == m-1) B = {x, y};
        //printf("%d, %d: %d\n", x, y, pardist[x][y].second);
        for(int i = 0; i < 4; ++i){
            int X = x + dx[i], Y = y + dy[i];
            if(inbound(X, Y) && pardist[X][Y].second == -1 && pardist[x][y].second + 1 < dist[X][Y]){
                q.push_back({X, Y});
                pardist[X][Y] = {i, pardist[x][y].second + 1};
            }
        }
    }
    if(B.first == -1){
        printf("NO");
    }else{
        printf("YES\n");
        int x = B.first, y = B.second;
        int p = pardist[x][y].first;
        vector<char> path;
        while(p >= 0){
            path.push_back(dir[p]);
            x -= dx[p];
            y -= dy[p];
            p = pardist[x][y].first;
        }
        printf("%d\n", (int)path.size());
        reverse(path.begin(), path.end());
        for(char c : path) printf("%c", c);
    }
}
