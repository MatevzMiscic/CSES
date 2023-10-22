#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    int n, a;
    scanf("%d", &n);
    vector<bool> arr(n, false);
    for(int i = 1; i < n; ++i){
        scanf("%d", &a);
        arr[a - 1] = true;
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] == false) printf("%d", i + 1);
    }
}