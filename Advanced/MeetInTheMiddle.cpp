#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

vector<int> arr;
unordered_map<ll, int> half;

int x;
ll subcount = 0;

void subsets1(int i, int j, ll sum){
    if(i == j){
        half[sum]++;
        half[sum + arr[i]]++;
        //printf("%lld\n", sum);
        //printf("%lld\n", sum + arr[i]);
    }else{
        subsets1(i + 1, j, sum);
        subsets1(i + 1, j, sum + arr[i]);
    }
}

void subsets2(int i, int j, ll sum){
    if(i == j){
        subcount += half[x - sum];
        subcount += half[x - sum - arr[i]];
    }else{
        subsets2(i + 1, j, sum);
        subsets2(i + 1, j, sum + arr[i]);
    }
}

int main(){
    int n, t;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; ++i){
        scanf("%d", &t);
        arr.push_back(t);
    }
    if(n == 1){
        for(int a : arr) subcount += (a == x);
    }else{
        int a = n / 2;
        int b = n - a;
        //printf("%d %d\n", a, b);
        subsets1(0, a - 1, 0);
        subsets2(a, n - 1, 0);
    }
    printf("%lld", subcount);
}