#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int ans;
int v[25][25];

bool check(int a, int b, int c, int d) {
    for(int i = a; i <= c; ++i)
        for(int j = b; j <= d; ++j)
            if(v[i][j]) return 0;
    return 1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j)
            cin >> v[i][j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = i; k <= n; ++k)
                for(int h = j; h <= m; ++h)
                    if(check(i, j, k, h)) 
                        ans = max(ans, (k - i + 1) * (h - j + 1));
    cout << ans << endl;
    return 0;
}

