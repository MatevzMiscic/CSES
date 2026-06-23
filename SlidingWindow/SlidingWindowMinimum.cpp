#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int x, a, b, c;

ll next(ll x){
    return (a * x + b) % c;
}

int main(){
    int n, k;
    scanf("%d %d %d %d %d %d", &n, &k, &x, &a, &b, &c);
    int first = x;
    deque<pair<int, int>> stack;
    for(int i = 0; i < k; ++i){
        while(!stack.empty() && first <= stack.back().first) stack.pop_back();
        stack.push_back({first, i});
        first = next(first);
    }
    ll total = stack.front().first;
    int second = x;
    for(int i = k; i < n; ++i){
        while(!stack.empty() && first <= stack.back().first) stack.pop_back();
        stack.push_back({first, i});
        while(!stack.empty() && stack.front().second <= i - k) stack.pop_front();
        total ^= stack.front().first;
        first = next(first);
        second = next(second);
    }
    printf("%lld\n", total);
}