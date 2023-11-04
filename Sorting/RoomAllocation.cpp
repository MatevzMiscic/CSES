#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <tuple>
 
using namespace std;
using ll = long long;

int main(){
    int n, a, b;
    scanf("%d", &n);
    vector<int> customers(n, -1);
    vector<int> rooms;
    vector<tuple<int, int, int>> times;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        times.push_back({a, -1, i});
        times.push_back({b, 1, i});
    }
    sort(times.begin(), times.end());
    int cur = 0;
    int max = 0;
    for(auto& tup : times){
        cur -= get<1>(tup);
        if(get<1>(tup) == -1){
            if(rooms.empty()){
                max = cur;
                rooms.push_back(max);
            }
            customers[get<2>(tup)] = rooms.back();
            rooms.pop_back();
        }else{
            rooms.push_back(customers[get<2>(tup)]);
        }
        //if(cur > max) max = cur;
    }
    printf("%d\n", max);
    for(int cust : customers) printf("%d ", cust);
}