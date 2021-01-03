#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d = 0;
    int a[1000 + 5];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int kase = 0;
            if (a[i] < a[j])
            {
                int f = j;
                for (int k = j + 1; k < n; k++)
                {
                    if (a[f] < a[k])
                    {
                        f = k;
                        kase++;
                    }
                }
                if (kase > d)
                    d = kase;
            }
        }
    }
    cout << d + 2;
    return 0;
}

//方法二，递推动归
const int maxn = 1010;
int a[maxn];
int maxlen[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxlen[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                maxlen[i] = max(maxlen[i], maxlen[j] + 1);
    }
    cout << *max_element(maxlen + 1, maxlen + n + 1);
    return 0;
}