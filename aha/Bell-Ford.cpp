#include<iostream>
using namespace std;

const int maxn = 1e9;
int main() {
    int dis[10], u[10], v[10], w[10];
    int check, flag;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> u[i] >> v[i] >> w[i];
    for(int i = 1; i <= n; ++i) 
        dis[i] = maxn;
    dis[1] = 0;

    // Bell-Ford 
    for(int k = 1; k <= n - 1; ++k) {
        check = 0;
        for(int i = 1; i <= n; ++i) 
            if(dis[v[i]] > dis[u[i]] + w[i]) {
                dis[v[i]] = dis[u[i]] + w[i];
                check = 1;
            }
        if(check == 0) break;
    }

    // 检查负权回路
    flag = 0;
    for(int i = 1; i <= m; ++i)
        if(dis[v[i]] > dis[u[i]] + w[i]) flag = 1;
    if(flag == 1) cout << "negative circle road";

    else {
        for(int i = 1; i <= n; ++i)
        cout << dis[i] << " ";
    }
    return 0;
}