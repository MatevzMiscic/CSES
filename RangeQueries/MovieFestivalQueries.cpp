#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct event{
    int time, type, idx;
    bool operator<(const event& other) const{
        if(time != other.time) return time < other.time;
        return type < other.type;
    }
};

constexpr int height = 20;
constexpr int QUERY = 0;
constexpr int START = 2;
constexpr int END = 1;

int main(){
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    vector<pair<int, int>> movies(n);
    vector<event> events(2*n + q);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        movies[i] = {a, b};
        events[2*i] = {a, START, i};
        events[2*i + 1] = {b, END, i};
    }
    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; ++i){
        scanf("%d %d", &a, &b);
        queries[i] = {a, b};
        events[2*n + i] = {a, QUERY, i};
    }
    vector<vector<int>> ancestors(n, vector<int>(height, -1));
    vector<int> ans(q);
    sort(events.begin(), events.end());
    int firstend = -1;
    for(auto it = events.rbegin(); it != events.rend(); ++it){
        vector<string> types = {"QUERY", "END", "START"};
        //printf("Event(%d, %s, %d)\n", it->time, types[it->type].c_str(), it->idx);
        if(it->type == START){
            if(firstend == -1 || movies[it->idx].second < movies[firstend].second) firstend = it->idx;
            //printf("firstend = %d\n", firstend);
        }else if(it->type == END){
            ancestors[it->idx][0] = firstend;
            //printf("ancestors[%d][0] = %d\n", it->idx, firstend);
            for(int h = 1; h < height; ++h){
                if(ancestors[it->idx][h - 1] == -1) break;
                ancestors[it->idx][h] = ancestors[ancestors[it->idx][h - 1]][h - 1];
                //printf("ancestors[%d][%d] = %d\n", it->idx, h, ancestors[it->idx][h]);
            }
        }else if(it->type == QUERY){
            //printf("firstend = %d, queries[%d].second = %d\n", firstend, it->idx, queries[it->idx].second);
            if(firstend == -1 || movies[firstend].second > queries[it->idx].second) ans[it->idx] = 0;
            else{
                int count = 1;
                int current = firstend;
                for(int h = height - 1; h >= 0; --h){
                    if(ancestors[current][h] != -1 && movies[ancestors[current][h]].second <= queries[it->idx].second){
                        count += (1 << h);
                        current = ancestors[current][h];
                    }
                }
                ans[it->idx] = count;
            }
        }
    }
    for(int i = 0; i < q; ++i){
        printf("%d\n", ans[i]);
    }
}