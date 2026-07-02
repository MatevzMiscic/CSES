#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> fin;
vector<int> swe;

int getF(int i){
    if(i < 1 || n < i) printf("Index out of bounds!\n");
    if(fin[i - 1] >= 0) return fin[i - 1];
    int f;
    printf("F %d\n", i);
    fflush(stdout);
    scanf("%d", &f);
    return fin[i - 1] = f;
}

int getS(int i){
    if(i < 1 || n < i) printf("Index out of bounds!\n");
    if(swe[i - 1] >= 0) return swe[i - 1];
    int s;
    printf("S %d\n", i);
    fflush(stdout);
    scanf("%d", &s);
    return swe[i - 1] = s;
}

int main(){
    string line;
    scanf("%d %d", &n, &k);
    fin.assign(n, -1);
    swe.assign(n, -1);
    if(k == 1){
        int a = getF(1), b = getS(1);
        printf("! %d\n", max(a, b));
    }else if(k == 2*n){
        int a = getF(n), b = getS(n);
        printf("! %d\n", min(a, b));
    }else{
        int m = max(0, k - n), M = min(k, n) + 1;
        //printf("m = %d, M = %d\n", m, M);
        int a = m, b = M;
        while(b - a > 1){
            int mid = (a + b) / 2;
            int f = getF(mid), s = getS(k + 1 - mid);
            if(f > s) a = mid;
            else b = mid;
        }
        //printf("a = %d, b = %d\n", a, b);
        if(a == m){
            int ans = (k <= n ? getS(k) : getF(k - n));
            printf("! %d\n", ans);
        }else if(b == M){
            int ans = (k <= n ? getF(k) : getS(k - n));
            printf("! %d\n", ans);
        }else{
            vector<int> scores = {getF(a), getF(b), getS(k + 1 - a), getS(k + 1 - b)};
            sort(scores.begin(), scores.end());
            printf("! %d\n", scores[2]);
        }
    }
}