#include<iostream>
using namespace std;

const int maxn = 1e9;
int main() {
    int n, m, a, b, c;
    int e[10][10], dis[10], book[10] = {0};
    int num = 0, sum = 0;

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            if(i == j) e[i][j] = 0;
            else e[i][j] = maxn;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        e[a][b] = c;
        e[b][a] = c;
    }
    for(int i = 1; i <= n; ++i) 
        dis[i] = e[1][i];

    // Prim
    book[1] = 1;
    num++;
    while(num < n) {
        int j;
        int min = maxn;
        for(int i = 1; i <= n; ++i) {
            if(book[i] == 0 && dis[i] < min) {
                min = dis[i];
                j = i;
            }
        }
        book[j] = 1;
        num++;
        sum += dis[j];
        for(int k = 1; k <= n; ++k) {
            if(book[k] == 0 && dis[k] > e[j][k]) 
                dis[k] = e[j][k];
        }
    }

    cout << sum << endl;
    return 0;
}