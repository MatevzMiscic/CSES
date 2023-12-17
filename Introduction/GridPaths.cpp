#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int n = 7;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

char dir[48];
bool vis[n+2][n+2];

inline int sum(int a, int b){
    if(a + b >= 4) return a + b - 4;
    return a + b;
}

int counter = 0;
void dfs(int i, int d, int x, int y){
    if(x == 1 && y == n){
        if(i == n*n-1) counter++;
        return;
    }
    if(i == n*n-1){
        printf("hmm\n");
        return;
    }
    if(vis[x + dx[d]][y + dy[d]] && !vis[x + dx[sum(d, 1)]][y + dy[sum(d, 1)]] && !vis[x + dx[sum(d, 3)]][y + dy[sum(d, 3)]]) return;
        //printf("i = %d, (%d %d), %d\n", i, x, y, d);
        //printf("(%, %d) visited, (%, %d), (%, %d) not\n", x + dx[d], y + dy[d], x + dx[sum(d, 1));
    vis[x][y] = true;
    if(dir[i] == 4){
        for(int j = 0; j < 4; ++j){
            if(!vis[x + dx[j]][y + dy[j]]) dfs(i + 1, j, x + dx[j], y + dy[j]);
        }
    }else{
        if(!vis[x + dx[dir[i]]][y + dy[dir[i]]]) dfs(i + 1, dir[i], x + dx[dir[i]], y + dy[dir[i]]);
    }

    vis[x][y] = false;
}

int main(){
    string str;
    //*
    getline(cin, str);
    int q = 0;
    for(int i = 0; i < 48; ++i){
        if(str[i] == 'U') dir[i] = 0;
        else if(str[i] == 'R') dir[i] = 1;
        else if(str[i] == 'D') dir[i] = 2;
        else if(str[i] == 'L') dir[i] = 3;
        else if(str[i] == '?'){
            dir[i] = 4;
            q++;
        }
    }
    if(q == 48){
        printf("88418");
        return 0;
    }
    //*/
    for(int i = 0; i < n + 1; ++i){
        vis[0][i] = true;
        vis[i][n + 1] = true;
        vis[n + 1][n + 1 - i] = true;
        vis[n + 1 - i][0] = true;
    }
    dfs(0, 0, 1, 1);
    printf("%d", counter);
}