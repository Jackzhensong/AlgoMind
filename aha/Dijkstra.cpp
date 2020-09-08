#include<iostream>
using namespace std;

const int maxn = 1e8;
int main() {
    int e[10][10], dis[10], book[10] = {0};
    int n, m, a, b, c, u, v, min;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) 
            if(i == j) e[i][j] = 0;
            else e[i][j] = maxn;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        e[a][b] = c;
    }

    for(int i = 1; i <= n; ++i) 
        dis[i] = e[1][i];
    book[1] = 1;

    // Dijkstra
    for(int i = 1; i <= n - 1; ++i) {
        min = maxn;
        for(int j = 1; j <= n; ++j) {
            if(book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for(v = 1; v <= n; ++v) {
            if(e[u][v] < maxn) {
                if(dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
    }
    
    for(int i = 1; i <= n; ++i)
        cout << dis[i] << " ";
    return 0;
}