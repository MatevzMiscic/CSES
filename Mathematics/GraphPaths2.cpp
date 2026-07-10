#include <cstdio>
#include <vector>
 
using namespace std;
using ll = long long;

constexpr ll INF = 1e18L + 1;
constexpr ll mod = 1e9 + 7;
 
int n;

vector<vector<ll>> mul(const vector<vector<ll>>& A, const vector<vector<ll>>& B){
    vector<vector<ll>> C(n, vector<ll>(n, INF));
    for(int i = 0; i < n; ++i){
        for(int k = 0; k < n; ++k){
            for(int j = 0; j < n; ++j){
                if(A[i][k] < INF && B[k][j] < INF) C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}
 
vector<vector<ll>> exp(const vector<vector<ll>>& A, ll b){
    if(b == 1) return A;
    vector<vector<ll>> C = exp(mul(A, A), b / 2);
    if(b & 1) C = mul(C, A);
    return C;
}
 
int main(){
    int m, k, a, b;
    ll c;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<ll>> A(n, vector<ll>(n, INF));
    for(int i = 0; i < m; ++i){
        scanf("%d %d %lld", &a, &b, &c);
        --a; --b;
        A[a][b] = min(A[a][b], (ll)c);
    }
    vector<vector<ll>> B = exp(A, k);
    printf("%lld", B[0][n-1] == INF ? -1 : B[0][n-1]);
}