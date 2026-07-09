#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool first = false;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            if(x % 2 == 1) first = true;
        }
        if(first) printf("first\n");
        else printf("second\n");
    }
}