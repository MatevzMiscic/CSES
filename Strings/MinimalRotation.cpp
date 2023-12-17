#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n, N;
string str;
vector<int> order;
vector<int> ranks;

inline int mod(int j){
    if(j >= n) return j - n;
    return j;
}

vector<int> sort(int k){
    vector<int> out(n);
    vector<int> freq(N, 0);
    for(int i = 0; i < n; ++i) freq[ranks[i]]++;
    //for(int a : freq) printf("%d ", a);
    //printf("\n");
    for(int i = 1; i < N; ++i) freq[i] += freq[i-1];
    //for(int a : freq) printf("%d ", a);
    //printf("\n");
    for(int i = n-1; i >= 0; --i){
        int j = order[i];
        //printf("%d: rank = %d, freq = %d\n", j, ranks[mod(j+k)], freq[ranks[mod(j+k)]]);
        out[--freq[ranks[mod(j+k)]]] = j;
    }
    //printf("\n");
    return out;
}

int main(){
    getline(cin, str);
    //str = "abaabbaa";
    n = str.size();
    if(n == 1){
        cout << str;
        return 0;
    }
    N = max('z' - 'a' + 1, n);
    for(int i = 0; i < n; ++i){
        order.push_back(i);
        ranks.push_back(str[i] - 'a');
    }
    //printf("ranks:\n");
    //for(int a : ranks) printf("%d ", a);
    //printf("\n");
    for(int k = 1; (1 << k) <= n; ++k){
        //printf("sort(%d):\n", k);
        order = sort(k);
        //for(int a : order) printf("%d ", a);
        //printf("\nsort(%d):\n", 0);
        order = sort(0);
        //for(int a : order) printf("%d ", a);
        //printf("\n");
        int r = 0;
        vector<int> newranks(n, 7);
        newranks[order[0]] = 0;
        for(int i = 1; i < n; ++i){
            if(ranks[order[i]] != ranks[order[i-1]] || ranks[mod(order[i] + k)] != ranks[mod(order[i-1] + k)]) ++r;
            //if(order[i] == 0) printf("ord = 0: %d, %d, %d, %d\n", ranks[order[i]], ranks[order[i-1]], ranks[order[mod(i+k)]], ranks[order[mod(i+k-1)]]);
            newranks[order[i]] = r;
        }
        ranks = newranks;
        if(ranks[order[1]] == 1) break;
        //printf("ranks:\n");
        //for(int a : ranks) printf("%d ", a);
        //printf("\n");
    }
    //for(int a : order) printf("%d ", a);
    int s = order[0];
    cout << str.substr(s, n-s);
    cout << str.substr(0, s);
}