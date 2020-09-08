#include<iostream>     // 拓补排序
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000;
int n, m, t;
int G[maxn][maxn];
int c[maxn], topo[maxn];

bool dfs(int u) {
    c[u] = -1;   //访问标志
    for(int v = 0; v < n; ++v)
        if(G[u][v]) {
            if(c[v] < 0) return false;   //存在有向环，失败退出
            else if(!c[v])  dfs(v);
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}
bool toposort() {
    t = n;
    memset(c, 0, sizeof(c));
    for(int u = 0; u < n; ++u)
        if(!c[u]) 
            if(!dfs(u)) return false;
    return true;
}

int main() {
    while(cin >> n >> m && n) {
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u][v] = 1;
        }
        
        if(toposort()) {
            for(int i = 0; i < n-1; ++i)
                printf("%d ", topo[i] + 1);
            printf("%d\n", topo[n-1] + 1);
        }
        else cout << "No" << endl;
    }
    return 0;
}