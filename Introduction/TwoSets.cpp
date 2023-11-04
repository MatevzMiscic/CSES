#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

vector<bool> half(ll n, int& size){
    vector<bool> out(n + 1, false);
    size = 0;
    ll m = n*(n + 1) / 4;
    //printf("%lld\n", m);
    ll sum = 0;
    for(int i = n; sum + i <= m; --i){
        //printf("sum: %lld, i: %d\n", sum, i);
        sum += i;
        out[i] = true;
        size++;
    }
    if(sum < m){
        out[m - sum] = true;
        size++;
    }
    return out;
}

int main(){
    int n;
    scanf("%d", &n);
    if(n % 4 == 0 || n % 4 == 3){
        printf("YES\n");
        int size = 0;
        vector<bool> out = half(n, size);
        printf("%d\n", size);
        for(int i = 1; i <= n; ++i) if(out[i]) printf("%d ", i);
        printf("\n%d\n", n - size);
        for(int i = 1; i <= n; ++i) if(!out[i]) printf("%d ", i);
    }else{
        printf("NO\n");        
    }
}