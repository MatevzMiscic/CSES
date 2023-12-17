#include <iostream>

using namespace std;
using ll = long long;

void hanoi(int k, int a, int b, int c){
    if(k == 1){
        printf("%d %d\n", a, c);
    }else{
        hanoi(k-1, a, c, b);
        printf("%d %d\n", a, c);
        hanoi(k-1, b, a, c);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 2, 3);
}