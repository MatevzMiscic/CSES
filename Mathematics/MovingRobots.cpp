#include <iostream>
#include <vector>

using namespace std;

constexpr int n = 8;
constexpr int m = n*n;

vector<vector<double>> matrix(){
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    vector<vector<double>> mat(m, vector<double>(m, 0.0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int coord = n*i + j;
            int neigh = 0;
            for(int d = 0; d < 4; ++d){
                int ni = i + di[d];
                int nj = j + dj[d];
                if(0 <= ni && ni < n && 0 <= nj && nj < n) neigh += 1;
            }
            for(int d = 0; d < 4; ++d){
                int ni = i + di[d];
                int nj = j + dj[d];
                int ncoord = n*ni + nj;
                if(0 <= ni && ni < n && 0 <= nj && nj < n) mat[ncoord][coord] = 1.0 / neigh;
            }
        }
    }
    return mat;
}

vector<vector<double>> mul(vector<vector<double>>& a, vector<vector<double>> & b){
    vector<vector<double>> c(m, vector<double>(m, 0.0));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            for(int k = 0; k < m; ++k){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

vector<vector<double>> exp(vector<vector<double>>& a, int k){
    if(k == 1) return a;
    auto b = mul(a, a);
    auto c = exp(b, k / 2);
    if(k % 2 == 1) c = mul(c, a);
    return c;
}

int main(){
    int k;
    scanf("%d", &k);
    auto tm = matrix();
    auto tmk = exp(tm, k);
    double expected = 0.0;
    for(int i = 0; i < m; ++i){
        double prob = 1.0;
        for(int j = 0; j < m; ++j){
            prob *= 1 - tmk[i][j];
        }
        expected += prob;
    }
    printf("%.6f\n", expected);
}