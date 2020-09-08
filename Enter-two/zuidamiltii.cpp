#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int s[n];
        int max = -100;
        for (int i = 0; i < n; ++i)
            cin>>s[i];
        for (int i = 0; i < n; ++i){
            long long big = 1;
            for(int j = i; j < n; ++j){
                big *= s[i];
                if (big > max)
                    max = big;
            }
        }
        if (max < 0)
            cout << 0 << endl;
        else
            cout << max << endl;
    }
    return 0;
}