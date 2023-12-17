#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

struct BIT{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    BIT(int n): n(n){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        arr[i] += x;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] += x;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum += tree[j];
        return sum;
    }
    ll query(int a, int b){
        return query(b) - query(a-1);
    }
    void print(){
        for(int a : arr) printf("%d ", a);
        printf("\n");
    }
};


int main(){
    int n, idx;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    BIT tree(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &idx);
        idx--;
        int a = -1, b = n;
        while(b - a > 1){
            int m = (a + b) / 2;
            //printf("%d: %d\n", m, m - tree.query(m));
            if(m - tree.query(m) < idx){
                a = m;
            }else{
                b = m;
            }
        }
        printf("%d ", arr[b]);
        tree.add(b, 1);
        //tree.print();
    }
}