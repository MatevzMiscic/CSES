#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int inf = 1e9;


int main(){
    vector<int> factors(1e6 + 1, inf);
    for(int i = 2; i <= 1e6; ++i){
        if(factors[i] == inf){
            for(int j = 2*i; j <= 1e6; j += i){
                factors[j] = min(factors[j], i);
            }
        }
    }


    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        ll divisors = 1;
        ll last = 0;
        ll curr = 0;
        while(x > 1){
            if(factors[x] == inf){
                if(x == last){
                    curr++;
                }else{
                    divisors *= curr + 1;
                    last = x;
                    curr = 1;
                }
                break;
            }else{
                if(factors[x] == last){
                    curr++;
                }else{
                    divisors *= curr + 1;
                    last = factors[x];
                    curr = 1;
                }
                x /= factors[x];
            }
        }
        divisors *= curr + 1;
        printf("%lld\n", divisors);
    }
}
