#include<iostream>
#include<cstring>
using namespace std;

char a[20][21];
int book[20][20];
int n, m, mx, my, maxnum;
int getnum(int i, int j) {
    int sum = 0;
    int x, y;
    x = i; y = j;
    while(a[x][y] != '#') {
        if(a[x][y] == 'G') sum++;
        x--;
    }
    x = i; y = j;
    while(a[x][y] != '#') {
        if(a[x][y] == 'G') sum++;
        x++;
    }
    x = i; y = j;
    while(a[x][y] != '#') {
        if(a[x][y] == 'G') sum++;
        y--;
    }
    x = i; y = j;
    while(a[x][y] != '#') {
        if(a[x][y] == 'G') sum++;
        y++;
    }
    return sum;
}

void dfs(int x, int y) {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int k, sum, tx, ty;
    sum = getnum(x, y);
    if(sum > maxnum) {
        maxnum = sum;
        mx = x;
        my = y;
    }
    for(int k = 0; k < 4; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 0 || tx > n - 1 || ty < 0 || ty > n - 1) continue;
        if(a[tx][ty] == '.' && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty);
        }
    }
    return ;
}

int main() {
    int bx, by;
    cin >> n >> m >> bx >> by;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
        
    book[bx][by] = 1;
    maxnum = getnum(bx, by);
    mx = bx; 
    my = by;
    dfs(bx, by);
    cout << mx << " " << my << endl << maxnum << endl;
    return 0;
}