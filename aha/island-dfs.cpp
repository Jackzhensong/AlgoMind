#include<iostream>
using namespace std;

int a[51][51];
int book[51][51] = {0};
int n, m, sum;

void dfs(int x, int y) {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int tx, ty;
    for(int k = 0; k < 4; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(a[tx][ty] > 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            sum++;
            dfs(tx, ty);
        }
    }
    return ;
}

int main() {
    int bx, by;
    cin >> n >> m >> bx >> by;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    book[bx][by] = 1;
    sum = 1;
    dfs(bx, by);
    cout << sum << endl;
    return 0;
}