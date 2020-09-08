#include<bits/stdc++.h>
using namespace std;

const int maxn = 10;
int a[maxn];
bool book[maxn];
int n, cnt = 0;

void dfs(int step) {
    if(step == n) {
        cnt ++;
        for(int i = 0; i < n; ++i)
            cout << a[i];
        cout << endl;
    }

    for(int i = 1; i <= n; ++i) { 
        if(!book[i]) {
            a[step] = i;
            book[i] = true;
            dfs(step+1);
            book[i] = false;
        }
    }
    return;
}

int main() {
    cin >> n;
    memset(book, 0, sizeof(book));
    dfs(0);
    cout << cnt << endl;
    return 0;
}

