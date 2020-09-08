#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 405;
char a[20][20];

struct note {
    int x, y;
};
int getnum(int i, int j) {
    int sum, x, y;
    sum = 0;
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

int main() {
    struct note que[maxn];
    int head, rear;
    int book[20][20] = {0};
    int bx, by, tx, ty, mx, my, sum, maxnum = 0;
    int n, m;
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    cin >> n >> m >> bx >> by;
    for(int i = 0; i < n; ++i)  cin >> a[i];
    
    head = 1;
    rear = 1;
    que[rear].x = bx;
    que[rear].y = by;
    rear++;
    book[bx][by] = 1;
    maxnum = getnum(bx, by);
    mx = bx; my = by;

    while(head < rear) {
        for(int k = 0; k < 4; ++k) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) continue;
            if(a[tx][ty] == '.' && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[rear].x = tx;
                que[rear].y = ty;
                rear++;
                sum = getnum(tx, ty);
                if(sum > maxnum) {
                    maxnum = sum;
                    mx = tx;
                    my = ty;
                }
            }
        }
        head++;
    }
    cout << mx << " " << my << endl << maxnum << endl;
    return 0;
}