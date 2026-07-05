#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> moves(k);
    for(int i = 0; i < k; ++i) scanf("%d", &moves[i]);
    vector<bool> winning(n + 1, false);
    winning[1] = true;
    printf("W");
    for(int i = 2; i <= n; ++i){
        for(int m : moves){
            if(i - m >= 0 && !winning[i - m]){
                winning[i] = true;
                break;
            }
        }
        if(winning[i]) printf("W");
        else printf("L");
    }
}