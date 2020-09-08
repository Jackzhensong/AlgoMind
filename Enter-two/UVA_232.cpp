#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 15;
char s[maxn][maxn];
int id[maxn][maxn];

int main() {
    int r, c;
    int kase = 0;
    while(cin >> r  && r != 0 && cin >> c) {
        int d = 1; 
        memset(id, 0, sizeof(id));
        for(int i = 0; i < r; ++i) cin >> s[i];
        for(int i = 0; i < r; ++i) 
            for(int j = 0; j < c; ++j) {
                if(s[i][j] == '*') continue;
                else if(i-1 < 0 || j-1 < 0 || s[i][j-1] == '*' || s[i-1][j] == '*')  { 
                    id[i][j] = d;
                    d++;
            }
        }
        if(kase >= 1) cout << endl;
        printf("puzzle #%d:\n", ++kase);
        printf("Across\n");
        int k;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j)
                if(id[i][j] != 0) {
                    printf("%3d.", id[i][j]);
                    for(k = j; k < c; ++k) {
                        if(s[i][k] == '*') { 
                            j = k;
                            break; 
                        }
                        else {
                            cout << s[i][k];
                            j = k;
                        }
                    }
                    cout << endl;
                }
        }
        int book[maxn][maxn];
        memset(book, 0, sizeof(book));

        printf("Down\n");
        for(int i = 0; i < r; ++i) 
            for(int j = 0; j < c; ++j) {
                if(id[i][j] != 0 && book[i][j] == 0) {
                    printf("%3d.", id[i][j]);
                    for(k = i; k < r; ++k) {
                        if(s[k][j] == '*') break;
                        cout << s[k][j];
                        book[k][j] = 1;
                    } 
                    cout << endl;
                } 
            }
    }
    return 0;
}