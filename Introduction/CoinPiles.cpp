#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        int x = 2*a - b, y = 2*b - a;
        if(x >= 0 && x % 3 == 0 && y >= 0 && y % 3 == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}