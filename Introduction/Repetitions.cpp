#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main(){
    string str;
    getline(cin, str);
    char cur = 'a';
    int len = 0;
    int max = 0;
    for(char c : str){
        if(c == cur){
            len++;
        }else{
            if(len > max) max = len;
            len = 1;
            cur = c;
        }
    }
    if(len > max) max = len;
    printf("%d", max);
}