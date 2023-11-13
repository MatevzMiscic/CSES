#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
 
int main(){
    int n, m, x, a, b;
    scanf("%d %d", &n, &m);
    vector<int> arr(n + 2);
    vector<int> pos(n + 2);
    vector<int> delta(n + 2, 0);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        arr[i] = x;
        pos[x] = i;
    }
    pos[0] = n + 1;
    pos[n + 1] = n + 1;
    int rounds = 0;
    for(int i = 1; i <= n; ++i){
        if(pos[i] < pos[i - 1]){
            delta[i] = 1;
            rounds += 1;
        }
    }
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        int A = arr[a], B = arr[b];
        pos[B] = a;
        pos[A] = b;
        arr[a] = B;
        arr[b] = A;
        int d = (pos[A] < pos[A - 1]);
        rounds += d - delta[A];
        delta[A] = d;
        d = (pos[B] < pos[B - 1]);
        rounds += d - delta[B];
        delta[B] = d;
        d = (pos[A + 1] < pos[A]);
        rounds += d - delta[A + 1];
        delta[A + 1] = d;
        d = (pos[B + 1] < pos[B]);
        rounds += d - delta[B + 1];
        delta[B + 1] = d;
        /*
        for(int d : arr) printf("%d ", d);
        printf("\n");
        for(int d : pos) printf("%d ", d);
        printf("\n");
        for(int d : delta) printf("%d ", d);
        printf("\n");
        */
        printf("%d\n", rounds);
    }
}
