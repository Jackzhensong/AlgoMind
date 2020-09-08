# include <bits/stdc++.h>
using namespace std;

const int N = 50;

int a[N][N][3];
int n;

void operate() {
    for(int i = n - 1; i >= 1; --i) 
        for(int j = 1; j <= i; ++j) 
            if(a[i+1][j][2] > a[i+1][j+1][2]) 
                a[i][j][2] += a[i+1][j][2];
            else {
                a[i][j][2] += a[i+1][j+1][2];
                a[i][j][0] = 1;
            }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= i; ++j) {
            cin >> a[i][j][1];
            a[i][j][2] = a[i][j][1];
            a[i][j][0] = 0;
        }
    operate();
    cout << a[1][1][2] << endl;
    return 0;
}

/// input ///
5
7
3 8
8 1 0
2 7 4 4 
4 5 2 6 5
/// output ///
30 

