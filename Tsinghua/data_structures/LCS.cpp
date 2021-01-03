///// 最长公共子序列(LCS) /////
// 输出所有的最长公共子序列 
#include <bits/stdc++.h>
using namespace std;

string X;
string Y;
vector< vector<int> > c;     // 动态规划表
set<string> lcs;            // set 保存所有的 lcs

int lcs_length(int m, int n) {
    c = vector<vector<int> >(m+1, vector<int>(n+1));    // 表的大小为 (m+1)*(n+1)

    for (int i = 0; i < m+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i == 0 || j == 0) c[i][j] = 0;      // 第一行和第一列置零

            else if(X[i-1] == Y[j-1]) c[i][j] = c[i-1][j-1] + 1;
            
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }
    return c[m][n];
}

void lcs_print(int i, int j, string lcs_str) {
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs_str.push_back(X[i-1]);
            --i;
            --j;
        }
        else
        {
            if (c[i-1][j] > c[i][j-1])      --i;
            else if (c[i-1][j] < c[i][j-1]) --j;
            else {
                lcs_print(i-1, j, lcs_str);
                lcs_print(i, j-1, lcs_str);
                return;
            }
        }    
    }
    reverse(lcs_str.begin(), lcs_str.end());
    lcs.insert(lcs_str);
}

int main() {
    cin >> X >> Y;
    int m = X.length();
    int n = Y.length();
    int length = lcs_length(m, n);
    cout << length << endl;

    string str;
    lcs_print(m, n, str);
    set<string>::iterator it = lcs.begin();
    for (; it != lcs.end(); ++it) cout << *it << endl;
    return 0;
}