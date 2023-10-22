#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n, m, k, x;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        a[i] = x;
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &x);
        b[i] = x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int match = 0;
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(j < m && b[j] < a[i] - k) ++j;
        if(j < m && b[j] <= a[i] + k){
            match++;
            j++;
        }
    }
    printf("%d", match);
}