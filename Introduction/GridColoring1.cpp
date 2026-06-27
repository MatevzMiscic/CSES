#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m, n;
    scanf("%d %d ", &m, &n);
    string chars = "ABCD";
    string line = "", prevline;
    for(int i = 0; i < m; i++){
        prevline = line;
        getline(cin, line);
        //printf("line %d has length %d: %s\n", i, line.length(), line.c_str());
        for(int j = 0; j < n; j++){
            for(char c : chars){
                if(c != line[j] && (prevline.empty() || c != prevline[j]) && (j == 0 || c != line[j-1])){
                    line[j] = c;
                    break;
                }
            }
        }
        printf("%s\n", line.c_str());
    }
}