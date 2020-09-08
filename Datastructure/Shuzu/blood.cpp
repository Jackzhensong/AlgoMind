#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k = 0, h = 0;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if ((a >= 90 && a <= 140) && (b >= 60 && b <= 90))
        {
            k++;
            if (h <= k)
                h = k;
        }
        else
            k = 0;
    }
    cout << h << endl;
    return 0;
}