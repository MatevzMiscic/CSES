#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int n = 8;

vector<vector<bool>> board;

bool valid(vector<int>& pos){
    int odd = 0, even = 0;
    for(int i = 0; i < n; ++i){
        if(!board[i][pos[i]]) return false;
        int a = 1 << (8 + i - pos[i]), b = 1 << (i + pos[i]);
        if((odd & a) > 0 || (even & b) > 0) return false;
        odd |= a;
        even |= b;
    }
    return true;
}

int main(){
    board.assign(n, vector<bool>(n, false));
    string str;
    for(int i = 0; i < n; ++i){
        getline(cin, str);
        for(int j = 0; j < n; ++j) board[i][j] = (str[j] == '.');
    }
    vector<int> pos = {0, 1, 2, 3, 4, 5, 6, 7};
    int count = 0;
    do{
        if(valid(pos)) count++;
    }while(next_permutation(pos.begin(), pos.end()));
    printf("%d", count);
}