//最长公共子序列
#include <algorithm>        
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;
char s1[MAX];
char s2[MAX];
int maxlen[MAX][MAX];
int main()
{
    while (cin >> s1 >> s2)
    {
        int slen1 = strlen(s1);
        int slen2 = strlen(s2);
        for (int i = 0; i <= slen1; ++i)
            maxlen[i][0] = 0;
        for (int j = 0; j <= slen2; ++j)
            maxlen[0][j] = 0;
            
        for (int i = 1; i <= slen1; ++i)
            for (int j = 1; j <= slen2; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
                else
                    maxlen[i][j] = max(maxlen[i][j - 1], maxlen[i - 1][j]);
            }
        cout << maxlen[slen1][slen2] << endl;
    }
    return 0;
}