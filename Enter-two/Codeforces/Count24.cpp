#include <iostream>
#include <cstdio>
using namespace std;


bool count24(int a[], int n) {
    if (n == 1) {
        return a[0] - 24 == 0 ? true : false;
    }
    
    for (int i = n - 1; i >= 1; --i) {
        int temp = a[i];
        int dest = a[i - 1];
        a[i] = 0;
        a[i - 1] = dest + temp;
        if (count24(a, i - 1)) return true;

        a[i - 1] = dest - temp;
        if (count24(a, i - 1)) return true;

        a[i - 1] = temp - dest;
        if (count24(a, i - 1)) return true;

        a[i - 1] = dest * temp;
        if (count24(a, i - 1)) return true;

        if (temp != 0) {
            a[i - 1] = dest / temp;
            if (count24(a, i - 1)) return true;
        }
        if (dest != 0) {
            a[i - 1] = temp / dest;
        }
    }
    return false;
}

int main()
{
    int a[5];
    while (true)
    {
        for (int i = 0; i < 4; i++)
            cin >> a[i];
        if (a[0] <= 0) break;

        cout << count24(a, 4) ? "YES" : "NO";

    }
    return 0;
}