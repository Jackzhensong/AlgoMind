#include <iostream>
#include <algorithm>
using namespace std;

int h[101];
int n;

void siftdown(int i)    // 大根堆
{
    for (int t = i * 2; t <= n; t *= 2)
    {
        if (t < n && (h[t] < h[t + 1])) t++;   // t 记录最大的子树下标
        if (!(h[i] < h[t])) break;
        swap(h[i], h[t]);
        i = t;
    }
    return;
}

void creat()
{
    for (int i = n / 2; i >= 1; --i)
        siftdown(i);
    return;
}

void heapsort()
{
    while (n > 1)
    {
        swap(h[1], h[n]);
        n--;
        siftdown(1);
    }
    return;
}


int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; ++i)
        cin >> h[i];
    n = num;

    creat();
    heapsort();

    for (int i = 1; i <= num; ++i)
        cout << h[i] << " ";
    return 0;
}
