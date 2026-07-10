#include <cstdio>
#include <array>
#include <vector>
 
using namespace std;
using ll = long long;
 
constexpr int N = 100;
constexpr ll mod = 1e9 + 7;
 
int n;

array<array<ll, N>, N> mul(const array<array<ll, N>, N>& A, const array<array<ll, N>, N>& B){
    array<array<ll, N>, N> C = {};
    for(int i = 0; i < n; ++i){
        for(int k = 0; k < n; ++k){
            for(int j = 0; j < n; ++j){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;
            }
        }
    }
    return C;
}
 
array<array<ll, N>, N> exp(const array<array<ll, N>, N>& A, ll b){
    if(b == 1) return A;
    array<array<ll, N>, N> C = exp(mul(A, A), b / 2);
    if(b & 1) C = mul(C, A);
    return C;
}
 
int main(){
    int m, k, a, b;
    scanf("%d %d %d", &n, &m, &k);
    array<array<ll, N>, N> A = {};
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        A[a - 1][b - 1] += 1;
    }
    array<array<ll, N>, N> B = exp(A, k);
    printf("%lld", B[0][n-1]);
}