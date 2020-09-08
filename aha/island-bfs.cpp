#include<iostream>
using namespace std;

struct note {
    int x;
    int y;
};

int main() {
    struct note que[2505];
    int head, rear;
    int a[51][51], book[51][51] = {0};
    int n, m;
    int bx, by, tx, ty, mx, my, sum, maxnum = 0;

    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    cin >> n >> m >> bx >> by;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    head = 1; 
    rear = 1;
    que[rear].x = bx;
    que[rear].y = by;
    rear++;
    book[bx][by] = 1;
    sum = 1；

    while(head < rear) {
        for(int k = 0; k < 4; ++k) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(a[tx][ty] > 0 && book[tx][ty] == 0) {
                sum ++;
                book[tx][ty] = 1;
                que[rear].x = tx;
                que[tear].y = ty;
                rear++;
            }
        }
        head++;
    }
    
    cout << sum << endl;
    return 0;
}