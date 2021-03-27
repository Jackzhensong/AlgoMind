#include<iostream>
#include <cstring>
using namespace std;

const int maxn = 1e8;
int e[101][101], book[101];
int n, m, sum = 0;

void dfs(int cur) {
    cout << cur << " ";
    sum++;
    if(sum == n) return ;
    for(int i = 1; i <= n; ++i) {
        if(e[cur][i] == 1 && book[i] == 0) {
            book[i] = 1;
            dfs(i);
        }
    }
    return ;
}

int main() {
    int a, b;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j)
            if(i == j) e[i][j] = 0;
            else e[i][j] = maxn;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }

    memset(book, 0, sizeof(book));
    book[1] = 1;
    dfs(1);
    return 0;  
}