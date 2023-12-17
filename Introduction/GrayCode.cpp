#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void code(int k, vector<int>& arr){
    if(k == 1){
        arr[1] = 1;
    }else{
        code(k-1, arr);
        int half = 1 << (k-1);
        for(int i = 0; i < half; ++i) arr[half + i] = arr[half - 1- i] | half;
    }    
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> arr(1 << n, 0);
    code(n, arr);
    for(int a : arr){
        for(int i = 0; i < n; ++i) printf("%d", (a >> i) & 1);
        printf("\n");
    }
}