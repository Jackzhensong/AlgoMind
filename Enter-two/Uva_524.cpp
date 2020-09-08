#include<bits/stdc++.h>
using namespace std;

const int maxn = 16 + 4;

int A[maxn], vis[maxn];
int n;
bool is_prime(int n) {
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

void dfs(int cur) {
    if(cur == n && is_prime(A[0] + A[n-1])) {    //递归边界， 测试第一个数和随后一个数
        for(int i = 0; i < n; ++i) printf("%d ", A[i]);
        printf("\n");
    }
    else for(int i = 2; i <= n; ++i)
        if(!vis[i] && is_prime(i + A[cur-1])) {
            A[cur] = i;
            vis[i] = 1;
            dfs(cur + 1);
            vis[i] = 0;
        }
}

int main() {
    int kase = 0;
    while(cin >> n && n > 0) {
        //if(kase++) cout << endl;
        cout << "Case " << ++kase << ": \n";
        memset(vis, 0, sizeof(vis));
        A[0] = 1;
        dfs(1);
        cout <<endl;
    }
    return 0;
}