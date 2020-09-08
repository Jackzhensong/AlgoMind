#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][4], *p;
    p = a[0];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cin >> *p++;

    p = a[0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << " " << *p++;
        cout << endl;
    }
    return 0;
}