#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;


int main(){
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    unordered_map<int, int> freq;
    ll ans = 0;
    int i = 0, j = 0;
    while(i < n){
        if(j < n && freq[x[j] ^ 123456789] == 0){
            freq[x[j] ^ 123456789] = 1;
            j += 1;
        }else{
            ans += j - i;
            freq[x[i] ^ 123456789] = 0;
            i += 1;
        }
    }
    printf("%lld\n", ans);
}