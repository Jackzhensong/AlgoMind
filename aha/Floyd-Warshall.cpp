#include<iostream>
using namespace std;

const int maxn = 1e8;
int main() {
    int e[10][10];
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(i == j) e[i][j] = 0;
            else e[i][j] = maxn;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        e[a][b] = c;
    }
    // Floyd
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= n; ++j) 
                if(e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            printf("%3d", e[i][j]);
        cout << endl;
    }
    return 0;
}