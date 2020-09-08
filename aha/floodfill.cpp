#include<iostream>
#include<cstdio>
using namespace std;

int a[51][51];
int book[51][51] = {0}, n, m, sum;

void dfs(int x, int y, int color) {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int tx, ty;
    a[x][y] = color;
    for(int k = 0; k < 4; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(a[tx][ty] > 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            sum++;
            dfs(tx, ty, color);
        }
    }
    return ;
}

int main() {
    int num = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] > 0) {
                num--;
                book[i][j] = 1;
                dfs(i, j, num);
            }
        }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) 
            printf("%3d", a[i][j]);
        cout << endl;
    }
    cout << -num << endl;
    return 0;
}
/*
10 10
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/