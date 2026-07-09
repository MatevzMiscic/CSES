#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll exp(ll a, ll p){
    if(p == 0) return 1;
    ll res = exp((a*a) % mod, p / 2);
    if(p % 2 == 1) res = (res * a) % mod;
    return res;
}

inline ll inv(ll a){
    return exp(a, mod - 2);
}

vector<vector<ll>> matrix;

vector<ll> solve(int n, int m){
    vector<bool> is_pivot(n, false);
    vector<int> pivots(m, -1);
    int row = 0;
    for(int j = 0; j < m; ++j){
        if(row >= n) break;
        for(int i = row; i < n; ++i){
            if(matrix[i][j] != 0){
                swap(matrix[i], matrix[row]);
                break;
            }
        }
        if(matrix[row][j] == 0) continue;
        pivots[j] = row;
        is_pivot[row] = true;
        ll inv_a = inv(matrix[row][j]);
        for(int k = 0; k <= m; ++k) matrix[row][k] = (matrix[row][k] * inv_a) % mod;
        for(int i = 0; i < n; ++i){
            if(i == row) continue;
            ll factor = matrix[i][j];
            for(int k = 0; k <= m; ++k){
                matrix[i][k] = (matrix[i][k] - factor * matrix[row][k]) % mod;
                if(matrix[i][k] < 0) matrix[i][k] += mod;
            }
        }
        row += 1;
    }
    for(int i = 0; i < n; ++i){
        if(!is_pivot[i] && matrix[i][m] != 0){
            return {};
        }
    }
    vector<ll> x(m, 0);
    for(int j = m - 1; j >= 0; --j){
        int row = pivots[j];
        if(row == -1) continue;
        x[j] = matrix[row][m];
        for(int k = j + 1; k < m; ++k){
            x[j] = (x[j] - matrix[row][k] * x[k]) % mod;
            if(x[j] < 0) x[j] += mod;
        }
    }
    return x;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    matrix.assign(n, vector<ll>(m + 1, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m + 1; ++j){
            scanf("%lld", &matrix[i][j]);
        }
    }
    vector<ll> sol = solve(n, m);
    if(sol.empty()){
        printf("-1\n");
    }else{
        for(ll x : sol) printf("%lld ", x);
        printf("\n");
    }
}