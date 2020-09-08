#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, k = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int n = i;
        while (n)
        {
            if (n % 10 == 2)
                k++;
            n /= 10;
        }
    }
    cout << k;
    return 0;
}