#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int devfact(int n, int a){
    int count = 0;
    int b = a;
    while(b <= n){
        count += n / b;
        b *= a;
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", devfact(n, 5));
}