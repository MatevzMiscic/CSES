#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;

multiset<pair<int, int>> movie_start;
multiset<pair<int, int>> movie_end;
multiset<int> members;

void remove(pair<int, int>& movie){
    movie_start.erase(movie_start.find(movie));
    movie_end.erase(movie_end.find(movie));
}

void print(multiset<pair<int, int>>& movies){
    for(auto& movie : movies){
        printf("[%d, %d], ", movie.first, movie.second);
    }
    printf("\n");
}

int main(){
    int n, k, a, b;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        movie_start.insert({a, b});
        movie_end.insert({b, a});
    }
    int count = 0;
    while(!movie_start.empty()){
        //printf("count = %d\n", count);
        auto& movie = *movie_end.begin();
        //printf("[%d, %d]\n", movie.second, movie.first);
        if(!members.empty() && *members.begin() <= movie.second){
            auto it = --members.upper_bound(movie.second);
            members.erase(it);
            members.insert(movie.first);
            count++;
            //printf("...take\n");
        }else if(members.size() < k){
            members.insert(movie.first);
            count++;
            //printf("...take\n");
        }
        movie_start.erase(movie_start.find({movie.second, movie.first}));
        movie_end.erase(movie_end.find(movie));
    }
    printf("%d", count);
}