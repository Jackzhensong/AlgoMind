#include<bits/stdc++.h> //pell数列
using namespace std;
#define M  1000010 
int a[M];
int main()
{
	int n;
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i < M; ++i) 
		a[i] = ( 2 * a[i-1] + a[i-2] ) % 32767;
	cin>>n;
	for(int i = 0;i < n; ++i) {
		int k;
		cin >> k;
		cout << a[k] << endl;
	}
	return 0;
}