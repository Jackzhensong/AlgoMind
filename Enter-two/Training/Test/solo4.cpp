
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5900 + 10;
char s[maxn];
string buf;
int p[maxn];

int main()
{
	int n, m = 0, ms = 0, x, y;
	int i, j;
	getline(cin, buf);
	n = buf.length();
	for (i = 0; i < n; ++i)
	{
		if(isalpha(buf[i])) {
			p[m] = i;
			s[m++] = toupper(buf[i]);
		}
    }

	for (i = 0; i < m; ++i)
	{
		for(j = 0; i - j >= 0 && i + j < m; ++j) {
			if(s[i - j] != s[i + j])  break;
			if(j * 2 + 1 > ms) {
				ms = j * 2 + 1;
				x = p[i - j];
				y = p[i + j];
			}
        }
        for(j = 0; i - j >= 0 && i - j + 1 < m; ++j) {
		    if(s[i - j] != s[i - j + 1])  break;
		    if(j * 2 + 2 > ms) {
            ms = j * 2 + 2;
            x = p[i - j];
            y = p[i + j + 1];
            }
		}
	}

	for(i = x; i <= y; ++i) 
		cout << buf[i];
	cout << endl;
	return 0;
}