#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);

    vector<ll> der(n + 2);
    der[1] = 0;
    der[2] = 1;
    for(int i = 3; i <= n; ++i){
        der[i] = ((i - 1) * (der[i - 1] + der[i - 2])) % mod;
    }
    cout << der[n];
}
