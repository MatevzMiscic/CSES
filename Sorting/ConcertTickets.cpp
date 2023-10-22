#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main(){
    int n, m, x;
    scanf("%d %d", &n, &m);
    multiset<int> tickets;
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        tickets.insert(x);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &x);
        auto it = tickets.upper_bound(x);
        if(it == tickets.begin()){
            printf("-1\n");
        }else{
            --it;
            printf("%d\n", *it);
            tickets.erase(it);
        }
    }
}