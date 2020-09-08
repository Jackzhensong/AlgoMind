/*#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
	Complex& operator= (const char *s){
		r=s[0]-'0';
		i=s[2]-'0';
		return *this;
	}
// 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }

	void Copy(const char *s){
		if(p) delete []p;
		if(s) {
			p=new char[strlen(s)+1];
			strcpy(p,s);
		}
		else p=NULL;
	}
	friend ostream & operator <<(ostream &os, const MyString &s) {
		os<<s.p;
		return os;
	}
	MyString (const MyString &s){
		if(s.p) {
			p=new char[strlen(s.p)+1];
			strcpy(p,s.p);
		}
		else p=NULL;
	}
	MyString & operator =(const MyString &s){
		if(this==&s) return *this;
		if( s.p) {
		p = new char[strlen(s.p) + 1];
			strcpy(p,s.p);
		}
		else
			p = NULL;
	}
	MyString & operator =(const char *s){
		if(p) delete []p;
		if(s){
			p=new char[strlen(s)+1];
			strcpy(p,s);
		}
		else p=NULL;
	}
// 在此处补充你的代码
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}