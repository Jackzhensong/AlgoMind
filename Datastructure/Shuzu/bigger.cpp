#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m1, m2, num = 0;
    while (cin >> n)
    {
        num++;
        if (num == 1)
        {
            m1 = n;
        }
        else if (num == 2)
        {
            if (n > m1)
            {
                m2 = m1;
                m1 = n;
            }
            else
                m2 = n;
        }
        else
        {
            if (n >= m1)
            {
                m2 = m1;
                m1 = n;
            }
            else if (n > m2)
                m2 = n;
        }
    }
    cout << m1 << " " << m2;
    return 0;
}