#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;

vector<vector<int>> sol;

int main(){
    int t, n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%d %d", &n, &m);
        sol.assign(n, vector<int>(m, -1));
        if(n % 3 != 0 && m % 3 != 0){
            printf("NO\n");
            continue;
        }
        bool swap = false;
        if(m % 3 != 0){
            swap = true;
            int temp = m;
            m = n;
            n = temp;
        }
        if(m == 3 && n % 2 == 1){
            printf("NO\n");
            continue;
        }
        if(n % 2 == 0){
            printf("YES\n");
            for(int i = 0; i < n/2; ++i){
                for(int j = 0; j < m/3; ++j){
                    int col = 2 * ((i + j) % 2);
                    sol[2*i][3*j] = col;
                    sol[2*i + 1][3*j] = col;
                    sol[2*i][3*j + 1] = col;
                    sol[2*i + 1][3*j + 1] = col + 1;
                    sol[2*i][3*j + 2] = col + 1;
                    sol[2*i + 1][3*j + 2] = col + 1;
                }
            }
        }
        
    }
}