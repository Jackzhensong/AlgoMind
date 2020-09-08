#include<iostream>
#include<algorithm>
using namespace std;

int n, m, root, index = 0;
int num[10], low[10], e[10][10];

void dfs(int cur, int fa) {
    index++;
    num[cur] = index;
    low[cur] = index;

    for(int i = 1; i <= n; ++i) {
        if(e[cur][i] == 1) {
            if(num[i] == 0) {
                dfs(i, cur);
                low[cur] = min(low[i], low[cur]);
                if(low[i] > num[cur]) 
                    cout << cur << " - " << i << endl;
            }
            else if(i != fa)
                low[cur] = min(low[cur], num[i]);
        }
    }
    return ;
}

int main() {
    int x, y;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            e[i][j] = 0;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y;
        e[x][y] = 1;
        e[y][x] = 1;
    }

    root = 1;
    dfs(1, root);
    return 0;
}

