#include<iostream>
using namespace std;

int f[1000] = {0};
int n, m, sum = 0;

void init() {
    for(int i = 1; i <= n; ++i) f[i] = i;   // 各自自成一派
    return;
}

int getf(int v) {
    if(f[v] == v)   return v;
    else {
        f[v] = getf(f[v]);
        return f[v];
    }
}

void merge(int v, int u) {
    int t1 = getf(v);
    int t2 = getf(u);
    if(t1 != t2)  f[t2] = t1;
    return;
} 

int main() {
    int x, y;
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y;
        merge(x, y);
    }
    for(int i = 1; i <= n; ++i){
        if(f[i] == i) sum++;
    }
    cout << sum << endl;
    return 0;
}