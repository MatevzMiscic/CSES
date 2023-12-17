#include <iostream>
#include <algorithm>
 
using namespace std;
using ll = long long;


int main(){
    string str;
    getline(cin, str);
    sort(str.begin(), str.end());
    int count = 0;
    do{
        count++;
    }while(next_permutation(str.begin(), str.end()));
    cout << count << "\n";
    do{
        cout << str << "\n";
    }while(next_permutation(str.begin(), str.end()));
}