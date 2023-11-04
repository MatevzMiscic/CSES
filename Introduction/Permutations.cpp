#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1");
    }else if(n >= 4){
        for(int i = 2; i <= n; i += 2) printf("%d ", i);
        for(int i = 1; i <= n; i += 2) printf("%d ", i);
    }else{
        printf("NO SOLUTION");
    }
}