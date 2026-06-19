#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

void printrange(int n, int d){
    for(int i = 1; i <= n; i++){
        printf("%d ", i + d);
    }
}

int main(){
    int t, n, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        if((a == 0 && b > 0) || (a > 0 && b == 0) || a + b > n){
            printf("NO\n");
        }else{
            printf("YES\n");
            printrange(n, 0);
            printf("\n");
            printrange(b, a);
            printrange(a, 0);
            printrange(n - a - b, a + b);
            printf("\n");
        }
    }
}