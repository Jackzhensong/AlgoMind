#include <cstdlib>
#include <iostream>
using namespace std;


int strlen(const char * s) {	
	int i = 0;
	for( ; s[i]; ++i);
	return i;
}

void strcpy(char * d, const char * s) {
	for(int i = 0; s[i]; ++i) 
		d[i] = s[i];
	// d[i] = 0;
}

int strcmp(const char * s1, const char * s2) {
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}

void strcat(char * d, const char * s) {
	int len = strlen(d);
	strcpy(d + len, s);
}



class MyString
{
	private:
	char *str;

	public:
	MyString():str(0) {}
	
	const char * c_str() const { return str;}

	MyString(const char *s1){
		if(s1){
			str = new char[strlen(s1) + 1];
			strcpy(str, s1);
		}
	}
	MyString(const MyString & s1) {
		if(s1.str){
			str = new char[strlen(s1.str) + 1];
			strcpy(str, s1.str);
		}
	 }	
	MyString  & operator =(const char *s1) {
		if(s1){
			str = new char[strlen(s1)+1];
			strcpy(str, s1);
		}
		else str = NULL;
		return *this;
	}

	MyString & operator =(const MyString & s1){
		if(s1.str){
			str=new char[strlen(s1.str)+1];
			strcpy(str,s1.str);
		}
		else 
			str = NULL;
		return *this;
	}

	friend MyString  operator +(const MyString & s1, const MyString & s2){
		MyString temp;
		if(temp.str) 
			delete [] temp.str;
		temp.str=new char[strlen(s1.str) + strlen(s2.str)+1];
		strcpy(temp.str, s1.str);
		strcat(temp.str, s2.str);
		return temp;
	}

	friend MyString operator + (const MyString & s2, const char *s1){
		MyString temp(s2);
		temp += s1;
		return temp;
	}
	
	char & operator[] (int index) const {
			return str[index];
	}

	friend ostream & operator <<(ostream &os,const MyString &s1){
		os<<s1.c_str();
		return os;
	}

	bool operator <(const MyString & s1){
		return strcmp(str, s1.str) < 0;
	}
	bool operator == (const MyString & s1){
		return strcmp(str, s1.str) == 0;
	}
	bool operator >(const MyString & s1){
		return strcmp(str, s1.str) > 0;
	}

	MyString & operator +=(const char *s1){
		int len = strlen(str) +strlen(s1);
		char *strnew;
		strnew = new char[len+1];
		strcpy(strnew, str);
		strcat(strnew, s1);
		return *this;
	}

	char * operator () (int begin, int length){
		char *substr;
		substr = new char[length+1];
		int index = 0;
		if(!str) return NULL;
		else {
			for(int i = begin; i < (begin + length); ++i)
				substr[index++] = str[i];
		}
		substr[index] = 0;
		return substr;
	}
// 在此处补充你的代码
};

CMyString &CMyString::operator = (const CMyString &str) {
    if (this == &str) return *this;
    delete[] m_pdata;
    m_pdata = NULL;
    m_pdata = new char[strlen(str.m_pdata) + 1];
    strcpy(m_pdata, str.m_pdata);
    return *this;
}

CMyString &CMyString::operator = (const CMyString &str) {
    if (this != &str) {
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pdata;
        strTemp.m_pdata = m_pdata;
        m_pdata = pTemp;
    }
    return *this;
}

int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	    return -1;
	else if( *s1 == *s2)
	    return 0;
	else if( *s1 > *s2 )
	    return 1;
}

int main()
{
	MyString s1("abcd-"),s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;

	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	                            //s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	                            //s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}


