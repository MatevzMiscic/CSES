#include <iostream>

using namespace std;

int isRed(int i){
    printf("? %d\n", i);
    fflush(stdout);
    string line;
    getline(cin, line);
    if(line == "R") return 1;
    else if(line == "B") return 0;
    else printf("IO Error!\n");
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    cin.ignore();
    int color = isRed(1);
    if(isRed(n) == color){
        printf("! %d\n", n);
    }else{
        int a = 1, b = n;
        while(b - a > 1){
            int mid = (a + b) / 2;
            int midColor = isRed(mid);
            int targetColor = (mid - a) % 2 == 0 ? color : 1 - color;
            if(midColor == targetColor){
                a = mid;
                color = midColor;
            }else{
                b = mid;
            }
        }
        printf("! %d\n", a);
    }
}