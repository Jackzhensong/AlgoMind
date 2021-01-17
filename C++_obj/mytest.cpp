#include<bits/stdc++.h>
using namespace std;
const int MAX = 110;

class CHugeInt {
	char buf[220];
	public:
	void reverse(char *p){
		int len=strlen(p);
		int i=0, j=len-1;
		while(i<=j){
			swap(p[i],p[j]);
			i++;
			j--;
		}
	}

	CHugeInt (char *p){
		memset(buf,0,sizeof(buf));
		strcpy(buf,p);
		reverse(buf);
	}

	CHugeInt (int n){
		memset(buf,0,sizeof(buf));
		sprintf(buf,"%d",n);
		reverse(buf);
	}

	CHugeInt operator + (CHugeInt a) {
		CHugeInt tmp(0);
		int carry=0;
		for(int i=0;i<210;++i){
			char c1=this->buf[i];
			char c2=a.buf[i];
			if(c1==0&&c2==0&&carry==0) break;
			if(c1==0) c1='0';
			if(c2==0) c2='0';
			int k=c1-'0'+c2-'0'+carry;
			if(k>=10) {
				carry=1;
				tmp.buf[i]=k-10+'0';
			}
			else {
				carry=0;
				tmp.buf[i]=k+'0';
			}
		}
		return tmp;
	}

	CHugeInt operator + (int n){
		return *this + CHugeInt(n);
	}

	friend CHugeInt operator +(int n, CHugeInt &a){
		return a+n;
	}

	friend ostream & operator <<(ostream & os,const CHugeInt &a){
		int len=strlen(a.buf);
		for(int i=len-1;i>=0;--i)
			cout<<a.buf[i];
		return os;
	}

	CHugeInt &operator +=(int n){
		*this=*this+n;
		return *this;
	}

	CHugeInt & operator ++() {
		*this=*this+1;
		return *this;
	}

	CHugeInt operator ++(int) {
		CHugeInt tmp(*this);
		*this=tmp+1;
		return tmp;
	}
// 在此处补充你的代码
};

int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}



