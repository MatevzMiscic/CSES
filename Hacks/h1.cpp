#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    ofstream out("hack1.txt");
    cout.rdbuf(out.rdbuf());
    cout << n << "\n";
    for(int i = 1; i < n; ++i){
        cout << i << " 0\n";
    }
    cout << n << " 0";
}