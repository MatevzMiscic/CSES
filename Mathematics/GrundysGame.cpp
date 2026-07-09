#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> precompute(int n){
    vector<int> g(n, 0);
    for(int i = 3; i < n; ++i){
        vector<bool> reach(i, false);
        for(int j = 1; 2*j < i; ++j){
            int state = g[j] ^ g[i - j];
            if(state < i) reach[state] = true;
        }
        int mex = 0;
        for(int j = 0; j < i; ++j){
            if(!reach[j]){
                mex = j;
                break;
            }
        }
        g[i] = mex;
        //printf("g[%d] = %d\n", i, mex);
    }
    return g;
}

int main() {
    int m = 2e3;
    vector<int> g = precompute(m);
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n >= m || g[n] > 0) printf("first\n");
        else printf("second\n");
    }
}
    