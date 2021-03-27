#include<iostream>
#include <cstring>

using namespace std;

const int maxn = 1e8;
int main() {
    int n, m, a, b, cur;
    int e[101][101], book[101];

    int que[1001];
    int head, rear;
    
    cin >> n >> m;
    memset(e, 0, sizeof(e));
    for(int i = 1; i <= n; ++i) {
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }

    head = rear = 1;
    que[rear] = 1;
    rear++;
    book[1] = 1;

    while(head < rear && rear <= n) {
        cur = que[head];
        for(int i = 1; i <= n; ++i) {
            if(e[cur][i] == 1 && book[i] == 0) {
                book[i] = 1;
                que[rear] = i;
                rear++;
            }
            if(rear > n) break;
        }
        head++;
    }
    for(int i = 1; i < rear; ++i) cout << que[i] << " ";
    return 0;
}

    // for(int i = 1; i <= n; ++i) 
    //     for(int j = 1; j <= n; ++j) 
    //         if(i == j) e[i][j] = 0;
    //         else e[i][j] = maxn;