#include<iostream>
using namespace std;

const int maxn = 1e8;
int minnum = 1e8;
int e[101][101], book[101];
int n, m;

void dfs(int cur, int dis) {
    if(dis > minnum) return ;
    
    if(cur == n) {
        // path[depth] = cur;
        if(dis < minnum) minnum = dis;
        return ;
    }

    for(int j = 1; j <= n; ++j) {
        if(e[cur][j] != maxn && book[j] == 0) {
            book[j] = 1;
            dfs(j, dis + e[cur][j]);
            book[j] = 0;
        }
    }
    return ;
}

int main() {
    int a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            if(i == j) e[i][j] = 0;
            else e[i][j] = maxn;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        e[a][b] = c;
    }

    book[1] = 1;
    dfs(1, 0);
    cout << endl << minnum << endl;
    return 0;
}

/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3

*/