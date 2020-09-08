#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << 2;
    for (int i = 3; i <= n; i += 2)
    {
        int k;
        for (k = 3; k < i; k += 2)
        {
            if (i % k == 0)
                break;
            if (k * k > i)
                break;
        }
        if (k * k > i)
            cout << " " << i;
    }
    return 0;
}