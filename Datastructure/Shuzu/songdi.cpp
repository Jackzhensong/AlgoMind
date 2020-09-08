#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a = m + 1, b = m + 1;
    for (int i = n; i < m; i++)
    { //取弟数，共m-n种取法
        if (i > (a + b) / 2 + 1)
            break;
        for (int j = i + 1; j <= m; j++)
        { //取兄数
            if (i + j > a + b)
                break;
            if ((i * j) % (i + j) == 0)
            { //发现兄弟数
                if (i + j < a + b)
                { //发现和更小的兄弟数
                    a = i;
                    b = j; //更新已找到的最佳兄弟数
                }
                else if (i + j == a + b && i < a) //发现和相同但弟数更小的兄弟数
                    a = i;
                b = j; //更新
            }
        }
    }
    if (a == m + 1)
        cout << "No solution.";
    else
        cout << a << "," << b;
    return 0;
}