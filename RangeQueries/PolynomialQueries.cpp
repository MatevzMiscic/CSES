#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
struct fenwick{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    fenwick(int n): n(n){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        if(i >= n) return;
        arr[i] += x;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] += x;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum += tree[j];
        return sum;
    }
    void print(){
        ll last = 0;
        for(int i = 0; i < n; ++i){
            ll curr = query(i);
            printf("%d ", (int)(curr - last));
            last = curr;
        }
        printf("\n");
    }
};

int main(){
    int n, q, x, t;
    ll a, b;
    scanf("%d %d", &n, &q);
    fenwick A(n);
    fenwick B(n);
    fenwick C(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        A.add(i, 2*x);
    }
    //A.print();
    for(int i = 0; i < q; ++i){
        scanf("%d %lld %lld", &t, &a, &b);
        a -= 1; b -= 1;
        if(t == 1){
            C.add(a, 1);
            C.add(b + 1, -1);
            B.add(a, 3-2*a);
            B.add(b + 1, 2*a-3);
            A.add(a, a*a-3*a+2);
            A.add(b + 1, (b-a+1)*(b-a+2)-a*a+3*a-2);
        }else{
            ll right = A.query(b) + b * B.query(b) + b*b * C.query(b);
            ll left = A.query(a - 1) + (a - 1) * B.query(a - 1) + (a - 1)*(a - 1) * C.query(a - 1);
            //printf("left: %d, A: %d, B: %d, C: %d\n", (int)left, (int)A.query(a-1), (int)B.query(a-1), (int)C.query(a-1));
            //printf("right: %d, A: %d, B: %d, C: %d\n", (int)right, (int)A.query(b), (int)B.query(b), (int)C.query(b));
            printf("%lld\n", (right - left) / 2);
        }
    }
}
