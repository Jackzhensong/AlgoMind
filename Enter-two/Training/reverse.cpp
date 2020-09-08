#include <bits/stdc++.h>   // 素数回环

using namespace std;

const int maxn = 1e4;
int prime[maxn], num = 0;
bool p[maxn] = {0};

void  findPrime(int a, int b) {
	for (int i = 2; i < maxn; ++i)
	{
		if(!p[i]) {
            if(i >= a && i <= b) 
			    prime[num++] = i;
			for (int j = i * 2; j < maxn; j += i) 
			{
				p[j] = true;
			}
		}
	}
}

int main()
{
	int a, b;
    int cnt = 0;
    string st, ch;
	cin >> a >> b;
    findPrime(a, b);
    for(int i = 0; i < num; ++i) {
        ch = to_string(prime[i]);
        st = ch;
        reverse(ch.begin(), ch.end());
        if(st == ch) cnt ++;
    }
	cout << cnt << endl;	
	return 0;
}