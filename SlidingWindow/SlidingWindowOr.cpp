#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int x, a, b, c;

ll next(ll x){
    return (a * x + b) % c;
}

struct queue{
    vector<pair<int, int>> back, front;

    void push(int x){
        if(back.empty()) back.push_back({x, x});
        else back.push_back({x, back.back().second | x});
    }
    void pop(){
        if(front.empty()){
            while(!back.empty()){
                int x = back.back().first;
                back.pop_back();
                if(front.empty()) front.push_back({x, x});
                else front.push_back({x, front.back().second | x});
            }
        }
        front.pop_back();
    }
    int query(){
        int res = 0;
        if(!back.empty()) res |= back.back().second;
        if(!front.empty()) res |= front.back().second;
        return res;
    }
};

int main(){
    int n, k;
    scanf("%d %d %d %d %d %d", &n, &k, &x, &a, &b, &c);
    queue win;
    int first = x;
    for(int i = 0; i < k; ++i){
        win.push(first);
        first = next(first);
    }
    int second = x;
    int total = win.query();
    for(int i = k; i < n; ++i){
        win.push(first);
        win.pop();
        total ^= win.query();
        first = next(first);
        second = next(second);
    }
    printf("%d", total);
}