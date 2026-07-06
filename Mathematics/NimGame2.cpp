#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int g = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            g ^= (x % 4);
        }
        if(g) printf("first\n");
        else printf("second\n");
    }
}