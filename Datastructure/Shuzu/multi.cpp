#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
bool flag[maxn + 10];

int main()
{
    for (int i = 2; i <= maxn; i++)
        flag[maxn] = true;

    for (int i = 2; i <= maxn; i++)
    {
        if (flag[i])
            for (int j = 2 * i; j <= maxn; j += i)
                flag[j] = false;
    }

    for (int i = 2; i <= maxn; i++)
        if (flag[i])
            cout << i << endl;

    return 0;
}