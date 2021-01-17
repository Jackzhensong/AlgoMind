#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50;
int w[maxn], d[maxn];
int f[maxn][maxn];
int N, M;

int fbag(int n, int m) {
    if(w[1] < m)   
        f[1][m] = d[1];
    else f[1][m] = 0;
    return f[n][m] = max(fbag(n - 1, m), fbag(n - 1, m - w[n]) + d[n]);
}

int main() {
    memset(f, 0, sizeof(f));
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> w[i] >> d[i];
    cout << fbag(N, M) << endl;
    return 0;
}