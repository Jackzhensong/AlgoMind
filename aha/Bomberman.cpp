#include<iostream>
using namespace std;

const int maxn = 25;

int main() {
    char a[maxn][maxn];
    int sum, map = 0;
    int n, m;
    int x, y, p, q;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) 
        cin >> a[i];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == '.') {
                sum = 0;
                x = i, y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G') sum++;
                    x--;
                }

                x = i, y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G') sum++;
                    x++;
                }
                
                x = i, y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G') sum++;
                    y--;
                }

                x = i, y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G') sum++;
                    y++;
                }

                if(sum > map) {
                    map = sum;
                    p = i, 
                    q = j;
                }
            }
        }
    }

    cout << "(" << p << ", " << q << ") " << map << endl;
    return 0;
}