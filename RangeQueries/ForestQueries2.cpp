#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

struct fenwick2d{
    int n;
    vector<vector<int>> arr;
    vector<vector<ll>> tree;
    fenwick2d(int n): n(n){
        arr.assign(n, vector<int>(n, 0));
        tree.assign(n + 1, vector<ll>(n + 1, 0));
    }
    void add(int x, int y, int val){
        arr[x][y] += val;
        for(int i = x + 1; i <= n; i += i & -i)
            for(int j = y + 1; j <= n; j += j & -j) 
                tree[i][j] += val;
    }
    void flip(int x, int y){
        if(arr[x][y] == 0) add(x, y, 1);
        else add(x, y, -1);
    }
    ll query(int x, int y){
        ll sum = 0;
        for(int i = x + 1; i > 0; i -= i & -i)
            for(int j = y + 1; j > 0; j -= j & -j) 
                sum += tree[i][j];
        return sum;
    }
    ll query(int a, int b, int c, int d){
        return query(b, d) - query(a-1, d) - query(b, c-1) + query(a-1, c-1);
    }
    void print(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                printf("%d", query(i, i, j, j));
            }
            printf("\n");
        }
    }
};


int main(){
    int n, q, t, a, b, c, d;
    scanf("%d %d ", &n, &q);
    fenwick2d tree(n);
    for(int i = 0; i < n; ++i){
        string line;
        getline(cin, line);
        for(int j = 0; j < n; ++j){
            if(line[j] == '*') tree.add(i, j, 1);
        }
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d", &t, &a, &b);
        a -= 1; b -= 1;
        if(t == 1){
            tree.flip(a, b);
        }else{
            scanf("%d %d", &c, &d);
            c -= 1; d -= 1;
            printf("%lld\n", tree.query(a, c, b, d));
        }
        //tree.print();
    }
}
