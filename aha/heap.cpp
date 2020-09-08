#include <iostream>
using namespace std;

int h[101];
int n;

void swap2(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    return;
}
void siftdown(int i)
{
    int t;
    while (i * 2 <= n)
    {
        if (h[i * 2] > h[i * 2 + 1]) t = i * i + 1;
        else t = i * 2;
        if (h[i] < h[t]) t = i;
        if (t != i)
        {
            swap2(t, i);
            i = t;
        }
        else break;
    }
    return;
}

void creat()
{
    for (int i = n / 2; i >= 1; --i)
        siftdown(i);
    return;
}

int deletemax()
{
    int t = h[1];
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; ++i)
        cin >> h[i];
    n = num;

    creat();
    for (int i = 1; i <= num; ++i)
        cout << deletemax() << " ";
    return 0;
}