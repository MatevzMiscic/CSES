#include <iostream>

using namespace std;

int main(){
    string line;
    int a = 0, b = 1e9;
    while(b - a > 1){
        int mid = (a + b) / 2;
        printf("? %d\n", mid);
        fflush(stdout);
        getline(cin, line);
        if(line == "YES") a = mid;
        else if(line == "NO") b = mid;
        else printf("IO Error!\n");
    }
    printf("! %d", b);
}