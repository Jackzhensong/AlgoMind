#include<iostream>
using namespace std;

const int maxn = 2505;
struct note {
    int x;
    int s;
};

int main() {
    struct note que[maxn];
    int e[51][51] = {0}, book[51] = {0};
    int n, m, a, b, cur, start, end, flag = 0;
    int head, rear;

    cin >> n >> m >> start >> end;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i == j) e[i][j] = 0;
            else e[i][j] = maxn;

    for(int i = 1; i <= m; ++i) {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }

    head = 1; rear = 1;
    que[rear].x = start;
    que[rear].s = 0;
    rear++;
    book[start] = 1;

    while(head < rear) {
        cur = que[head].x;
        for(int j = 1; j <= n; ++j) {
            if(e[cur][j] != maxn && book[j] == 0) {
                book[j] = 1;
                que[rear].x = j;
                que[rear].s = que[head].s + 1;
                rear++;
            }
            if(que[rear - 1].x == end) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
        head++;
    }

    cout << que[rear-1].s << endl;
    return 0;
}