#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main(){
    int n, x, p;
    scanf("%d %d", &n, &x);
    multiset<int> child;
    for(int i = 0; i < n; ++i){
        scanf("%d", &p);
        child.insert(p);
    }
    int gond = 0;
    while(!child.empty()){
        gond++;
        int a = *child.begin();
        //printf("%d\n", a);
        child.erase(child.begin());
        if(child.empty()) break;
        auto it = child.upper_bound(x-a);
        if(child.begin() != it){
            --it;
            //printf("%d\n", *it);
            child.erase(it);
        }
        //printf("gond = %d\n", gond);
    }
    printf("%d", gond);
}