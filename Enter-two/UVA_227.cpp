#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 50;
int main() {
    char s[maxn][maxn];
    char c;
    int x, y, kase = 0;
    while(1) {
        for(int i = 0; i < 5; ++i) {
                cin.getline(s[i], sizeof(s[i]));
                if(s[0][0] == 'Z') return 0;
                for(int j = 0; j < 5; ++j) {
                    if(s[i][j] == '\0' || s[i][j] == ' ') { x = i; y = j; }
                }
        }
        int flag = 0;
        while((c = getchar()) != '0') {
            if(c == 'A' && x - 1 >= 0) {
                s[x][y] = s[x-1][y];
                s[x-1][y] = ' ';
                x--;
            }
            else if(c == 'B' && x + 1 < 5) {
                s[x][y] = s[x+1][y];
                s[x+1][y] = ' ';
                x++;
            }
            else if(c == 'R' && y + 1 < 5) {
                s[x][y] = s[x][y+1];
                s[x][y+1] = ' ';
                y++;
            }
            else if(c == 'L' && y - 1 >= 0) {
                s[x][y] = s[x][y-1];
                s[x][y-1] = ' ';
                y--;
            }
            else if(c == '\n') continue;
            else flag = 1;
        }
        if(kase >= 1) cout << endl;
        printf("Puzzle #%d:\n", ++kase);
        if(flag == 1) 
            cout << "This puzzle has no final configuration." << endl;
        else {
            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < 5; ++j) {
                    if(j == 0) printf("%c", s[i][j]);
                    else printf(" %c", s[i][j]);
                }
                printf("\n");
            }
        }
        getchar();
    }
    return 0;
}