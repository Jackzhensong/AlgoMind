#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 100;
int n, m, p, q, minsp = 1e6;
int a[maxn][maxn], book[maxn][maxn];

void dfs(int x, int y, int step) {
    int next[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int tx, ty, k;
    if(x == p && y == q) {
        if(step < minsp) minsp = step;
        return;
    }
    for(int k = 0; k < 4; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
}

int main() {
    int bx, by;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    cin >> bx >> by >> p >> q;
    memset(book, 0, sizeof(book));
    book[bx][by] = 1;
    dfs(bx, by, 0);
    cout << minsp << endl;
    return 0;
}