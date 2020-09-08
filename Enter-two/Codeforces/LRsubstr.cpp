#include <iostream>     //最长上升子序列
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1010;
int a[MAX], maxlen[MAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxlen[i] = 1;
    }
    
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if(a[i] > a[j])
                maxlen[i] = max(maxlen[i], maxlen[j] + 1);
    sort(maxlen + 1, maxlen + n + 1);
    cout << maxlen[n] << endl;
    return 0;
}