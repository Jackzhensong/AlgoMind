#include<iostream>
#include<cstdio>
using namespace std;

int book[11][11]  = {0};
int n, m, num;

void dfs(int x, int y, int step) {
    int next[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    int tx, ty;

    if(step == n * m) { 
        num++;  
        return; 
    }

    for(int k = 0; k < 8; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) continue;
        if(book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
 }

int main() {
    int T;
    cin >> T;
    int bx, by;
    while(T--) {
        cin >> n >> m >> bx >> by;
        num = 0;
        book[bx][by] = 1;
        dfs(bx, by, 1);
        cout << num << endl;
    }
    return 0;
}


    /*bool p = true;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(book[i][j] == 0) {
                p = false;
                break;
            }
    if(p == true) { 
        num++; 
        return;
    }
    */