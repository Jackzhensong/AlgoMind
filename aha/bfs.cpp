#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 2505;

struct note {
    int x, y;
    // int f;
    int s;
};

struct note que[maxn];
int head, rear;

int a[51][51] = {0};
int book[51][51] = {0};
int n, m, bx, by, p, q;

void bfs() {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    head = 1; rear = 1;
    que[rear].x = bx;
    que[rear].y = by;
    que[rear].s = 0;
    //que[rear].f = 0;
    rear++;
    book[bx][by] = 1;

    int flag = 0;
    int tx, ty;
    while(head < rear) {
        for(int k = 0; k < 4; ++k) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(a[tx][ty] == 0 && book[tx][ty] == 0) {   // 判断是否是障碍物或已经在路径中
                book[tx][ty] = 1;
                que[rear].x = tx;
                que[rear].y = ty;
                //que[rear].f = head;
                que[rear].s = que[head].s + 1;
                rear++;
            }
            if(tx == p && ty == q) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
        head++;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    cin >> bx >> by >> p >> q;
    bfs();
    cout << que[rear-1].s << endl;
    return 0;
}