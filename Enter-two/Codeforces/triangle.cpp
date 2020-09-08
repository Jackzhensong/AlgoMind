#include <iostream>        //数字三角形
#include <cstring>     
#include<algorithm>
using namespace std;

const int MAX = 10;
int str[MAX][MAX];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> str[i][j];
            
    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
            str[n][j] = max(str[n][j], str[n][j + 1]) + str[i][j];
    cout << str[n][1] << endl;
    return 0;
}