#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    char s[5][5];
    char order[100];
    int x, y, kase = 1;
    while(true) {
        memset(s, 0, sizeof(s));
        memset(order, 0, sizeof(order));
        for(int i = 0; i < 5; ++i) 
            for(int j = 0; j < 5; ++j) {
                scanf("%c", &s[i][j]);
                if(s[i][j] == ' ') { x = i; y = j; }
            }
        if(strcmp(s[0], "Z") == 0)  break;
        printf("Puzzle #%d:\n", kase+=);
        int flag = 0;
        for(int i = 0; i < maxn; ++i) {
            cin >> order[i];
            if(order[i] == '0') break;
            if(order[i] == 'A') {
                if(y - 1 < 0) { flag = 1; break; }
                s[x][y] = s[x][y-1];
                y--;
            }
            if(order[i] == 'B') {
                if(y + 1 > 4) { flag = 1; break; }
                s[x][y] = s[x][y+1];
                y++;
            }
            if(order[i] == 'R') {
                if(x - 1 < 0) { flag = 1; break; }
                s[x][y] = s[x-1][y];
                x--;
            }
            if(order[i] == 'L') {
                if(x + 1 > 4) { flag = 1; break; }
                s[x][y] = s[x+1][y];
                x++;
            }
        }
        if(flag == 1) cout << "This puzzle has no final configuration." << endl;
        if(flag == 0) {
            for(int i = 0; i )
        }

        
    }
}