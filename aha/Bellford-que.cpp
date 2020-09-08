#include<iostream>
using namespace std;

const int maxn = 1e9;
int main() {
    int n, m;
    int u[8], v[8], w[8];
    int first[10], next[10];
    int dis[10] = {0}, book[10] = {0};

    int que[101] = {0};
    int head = 1, rear = 1;

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        dis[i] = maxn;
    dis[1] = 0;

    for(int i = 1; i <= n; ++i) first[i] = -1;
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    que[rear] = 1;
    rear++;
    book[1] = 1;

    while(head < rear) {
        int k = first[que[head]];
        while(k != -1) {
            if(dis[v[k]] > dis[u[k]] + w[k]) {
                dis[v[k]] = dis[u[k]] + w[k];
                if(book[v[k]] == 0) {
                    book[v[k]] = 1;
                    que[rear] = v[k];
                    rear++;
                }
            }
            k = next[k];
        }
        book[que[head]] = 0;
        head++;
    }

    for(int i = 1; i <= n; ++i) 
        cout << dis[i] << " ";
    return 0;
}