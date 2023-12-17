#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> zalg(const string& str){
    int n = str.size();
    vector<int> z(n, 0);
    int x = 0, y = 0;
    for(int i = 1; i < n; ++i){
        z[i] = max(0, min(z[i - x], y - i + 1));
        while(i + z[i] < n && str[i + z[i]] == str[z[i]]) z[i]++;
        if(i + z[i] > y + 1){
            x = i; y = i + z[i] - 1;
        }
    }
    return z;
}

int main(){
    string str;
    getline(cin, str);
    vector<int> z = zalg(str);
    int n = str.size();
    for(int i = 1; i <= n; ++i){
        if(z[n - i] == i) printf("%d ", i);
    }
}