#include <bits/stdc++.h>
using namespace std;

int color[100];
int flag = 0;
int ans = 0;

int OK(int k, int c[][100])          // 判断顶点 k 的着色是否发生冲突 
{
    for(int i = 1; i < k; ++i) 
        if(c[k][i] == 1 && color[i] == color[k]) return 0;
    return 1;
}

int graphcolor(int n, int m, int c[][100])  
{
    for(int i = 1; i <= n; ++i) color[i] = 0;    // 初始化

    int k = 1;
    while(k >= 1) {
        color[k] += 1;
        while(color[k] <= m) {
            if(OK(k, c)) break;
            else color[k] += 1;                  // 搜索下一种颜色
        }
        if(color[k] <= m && k == n) {            // 求解完，输出解 
            flag = 1;
            ans ++;
        }

        else if(color[k] <= m && k < n)          // 向前试探，处理下一个顶点
            k += 1;

        else {                          // 回溯 
            color[k] = 0;
            k -= 1;
        }
    }
    return flag;
}

int main()
{
    int u, v, k, n, m;
    int c[100][100] = {{0, 0}};
    cin >> n >> k >> m;
    while (k--)
    {
        cin >> u >> v;
        c[u][v] = 1;
        c[v][u] = 1;
    }

    graphcolor(n, m, c);
    cout << ans << endl;
    return 0;
}