#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string line;
    int n;
    cin >> n;
    cin.ignore();
    vector<int> perm(n + 1, 0);
    for(int i = 0; i < 10; ++i){
        cout << "? ";
        for(int j = 1; j <= n; ++j){
            cout << (((j >> i) & 1) ? "1" : "0");
        }
        cout << "\n";
        cout.flush();
        getline(cin, line);
        //cout << "line: " << line << "\n";
        for(int j = 1; j <= n; ++j){
            //cout << "read char: '" << line[j - 1] << "'\n";
            if(line[j - 1] == '1') perm[j] |= (1 << i);
        }
    }
    /*
    vector<int> inv(n + 1, 0);
    for(int j = 1; j <= n; ++j){
        //cout << j << " -> " << perm[j] << "\n";
        inv[perm[j]] = j;
    }
    */
    cout << "! ";
    for(int j = 1; j <= n; ++j){
        cout << perm[j] << " ";
    }
    cout << "\n";
}