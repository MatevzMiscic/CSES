#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

int main(){
    int n, q, x, a, b;
    scanf("%d %d", &n, &q);
    vector<int> prexor(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        prexor[i] = prexor[i - 1] ^ x;
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &a, &b);
        printf("%d\n", prexor[b] ^ prexor[a - 1]);
    }
}