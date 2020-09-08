/*#include <iostream> 
using namespace std;
class MyInt 
{ 
	int nVal; 
	public: 
	MyInt( int n) { nVal = n ;}
    MyInt & operator -(const int d){
        nVal-=d;
        return *this;
    }
    operator int(){
        return nVal;
    }
// 在此处补充你的代码
}; 
int Inc(int n) {
	return n + 1;
}
int main () { 
	int n;
	while(cin >>n) {
		MyInt objInt(n); 
		objInt-2-1-3; 
		cout << Inc(objInt);
		cout <<","; 
		objInt-2-1; 
		cout << Inc(objInt) << endl;
	}
	return 0;
}*/

/*#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    int *p;
    int r,c;
    public:
    Array2(){p=NULL;}
    Array2(int x,int y):r(x),c(y){
        p=new int[r*c];
    }
    Array2(Array2 & a):r(a.r),c(a.c){
        p=new int[r*c];
        memcpy(p,a.p,sizeof(int)*r*c);
    }
    Array2 & operator =(const Array2& s){
        if(p) delete []p;
        r=s.r; c=s.c;
        p=new int [r*c];
        memcpy(p,s.p,sizeof(int )*r*c);
        return *this;
    }
    ~Array2(){
        if(p) delete []p;
    }
    int * operator [](int i){
        return p+i*c;
    }
    int & operator() (int i,int j){
        return p[i*c+j];
    }
// 在此处补充你的代码
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}*/

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
    char arra[220];
    public:
    void reverse(char *s){
        int len=strlen(s);
        int i=0,j=len-1;
        while(i<=j){
            swap(s[i],s[j]);
            ++i;
            --j;
        }
    }
    CHugeInt(char *s){
        memset(arra,0,sizeof(arra));
        strcpy(arra,s);
        reverse(arra);
        //for(int i=0;i<MAX;++i)
        //arra[i]=s[i];
    }
    CHugeInt(int n){
        memset(arra,0,sizeof(arra));
        sprintf(arra,"%d",n);
        reverse(arra);
    }
    //CHugeInt(int val):n(val){ }
    CHugeInt &operator +(int n){
        return *this+CHugeInt(n);
    }
    CHugeInt &operator +(const CHugeInt &n) const{
        
    }
    friend ostream & operator <<(ostream &os,CHugeInt & s){
        os<<s.;
        return os;
    }
    CHugeInt & operator ++(CHugeInt &b){
        b.++;
        return *this;
    }
    CHugeInt operator ++(CHugeInt &b){

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