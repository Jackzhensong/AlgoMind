#include <bits/stdc++.h>
using namespace std;
long long c(int n, int m)
{
    if (n < n - m)
        m = n - m;
    long long ans = 1;
    for (int i = m + 1; i <= n; i++)
        ans *= i;
    for (int i = 1; i <= n - m; i++)
        ans /= i;
    return ans;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    cout << c(n, m) << endl;
    return 0;
}