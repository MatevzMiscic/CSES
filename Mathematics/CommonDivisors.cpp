#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int inf = 1e9;


int main(){
    int n, x;
    scanf("%d", &n);
    vector<int> arr(1e6 + 1, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        arr[x]++;
    }
    for(int i = 1e6; i >= 1; --i){
        int div = 0;
        for(int j = i; j <= 1e6; j += i) div += arr[j];
        if(div >= 2){
            printf("%d", i);
            break;
        }
    }
}
