#include<iostream>
using namespace std;

int e[101][101];
int match[101], book[101];
int n, m;

int dfs(int u) {
    for(int i = 1; i <= n; ++i) {
        if(book[i] == 0 && e[u][i] == 1) {
            book[i] = 1;
            if(match[i] == 0 || dfs(match[i])) {
                match[i] = u;
                match[u] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int t1, t2, sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> t1 >> t2;
        e[t1][t2] = 1; 
        e[t2][t1] = 1;
    }

    for(int i = 1; i <= n; ++i) match[i] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) book[j] = 0;
        if(dfs(i)) sum++;
    }

    cout << sum << endl;
    return 0;
}