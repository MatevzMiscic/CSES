#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string line;
    int n;
    cin >> n;
    vector<int> perm = {0};
    for(int i = 1; i < n; ++i){
        int a = -1, b = i;
        while(b - a > 1){
            int mid = (a + b) / 2;
            cout << "? " << perm[mid] + 1 << " " << i + 1 << endl;
            cin >> line;
            if(line == "YES") a = mid;
            else if(line == "NO") b = mid;
            else cout << "IO Error!" << endl;
        }
        perm.insert(perm.begin() + b, i);
        //cout << "Perm: ";
        //for(int a : perm) cout << a + 1 << " ";
        //cout << "\n";
    }
    vector<int> inv(n);
    for(int i = 0; i < n; ++i) inv[perm[i]] = i + 1;
    cout << "!";
    for(int a : inv) cout << " " << a;
}