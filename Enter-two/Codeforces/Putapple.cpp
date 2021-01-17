#include <iostream>      //放苹果
using namespace std;

int putapple(int m, int n)
{
    if (m < n)
        return putapple(m, m);
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;
    return putapple(m, n - 1) + putapple(m - n, n);
}

int main()
{
    int m, n, t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        cout << putapple(m, n) << endl;
    }
    return 0;
}