#include<bits/stdc++.h>
using namespace std;

void search(int cur) {
    if(cur == n)    tot++;
    else for(int i = 0; i < n; ++i) {
        int ok = 1;
        C[cur] = i;
        for(int j = 0; j < cur; ++j)
            if(C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
                { ok = 0; break; }
        if(ok) search(cur + 1);
    }
}

void search(int cur) {
    if(cur == n)    tot++;
    else for(int i = 0; i < n; ++i) {
        if(!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
            C[cur] = i;
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;  //修改全局变量
            search(cur + 1);
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;  //改回全局变量
        }
    }
}

