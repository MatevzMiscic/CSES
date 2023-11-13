#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int med = arr[n/2];
    ll cost = 0;
    for(int a : arr) cost += abs(a - med);
    printf("%lld", cost);
}
