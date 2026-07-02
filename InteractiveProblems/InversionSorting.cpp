#include <iostream>

using namespace std;

int inv = 1, pre = 1;

bool reverse(int a, int b){
    pre = inv;
    if(b <= a) return false;
    printf("%d %d\n", a, b);
    cout.flush();
    int x;
    scanf("%d", &x);
    inv = x;
    return x == 0;
}

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1 1\n");
        cout.flush();
        scanf("%d", &n);
        return 0;
    }
    if(reverse(1, n)) return 0;
    for(int i = 2; i <= n; i++){
        if(reverse(1, i)) return 0;
        int diff = inv - pre - (i - 1)*(i - 2) / 2;
        int h = (i - 1 - diff) / 2;
        //printf("diff: %d, h = %d\n", diff, h);
        if(reverse(1, i)) return 0;
        if(reverse(i - h, i)) return 0;
        if(reverse(i - h + 1, i)) return 0;
    }
}