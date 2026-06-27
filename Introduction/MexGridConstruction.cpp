#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> arr(n, vector<int>(n, -1));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            vector<bool> taken(2*n, false);
            for(int k = 0; k < i; ++k) taken[arr[k][j]] = true;
            for(int k = 0; k < j; ++k) taken[arr[i][k]] = true;
            int num = 0;
            while(taken[num]) ++num;
            arr[i][j] = num;
            printf("%d ", num);
        }
        printf("\n");
    }
}
