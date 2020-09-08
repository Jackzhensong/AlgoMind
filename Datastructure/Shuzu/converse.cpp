#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int k = 1;
    cin >> n;
    while (n != 0)
    {
        if (n % 10 != 0 && k == 1)
        {
            cout << n % 10;
            k++;
        }
        else if (k != 1)
            cout << abs(n % 10);
        n /= 10;
    }
    return 0;
}