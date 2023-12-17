#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;


int main(){
    string str;
    getline(cin, str);
    vector<int> freq('Z'-'A' + 1, 0);
    for(char c : str) freq[c - 'A']++;
    int odd = 0, oddfreq;
    char oddchar;
    for(int i = 0; i <= 'Z'-'A'; ++i){
        if(freq[i] % 2 == 1){
            odd++;
            oddfreq = freq[i];
            oddchar = 'A' + i;
            freq[i] = 0;
        }else{
            freq[i] /= 2;
        }
    }
    if(odd > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    for(int i = 0; i <= 'Z'-'A'; ++i){
        for(int j = 0; j < freq[i]; ++j) printf("%c", 'A' + i);
    }
    if(odd == 1){
        for(int j = 0; j < oddfreq; ++j) printf("%c", oddchar);
    }
    for(int i = 'Z'-'A'; i >= 0; --i){
        for(int j = 0; j < freq[i]; ++j) printf("%c", 'A' + i);
    }
}