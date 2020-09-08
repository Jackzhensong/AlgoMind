#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*char s[10];
char used[10];
char result[10];
int slen;

void permutation(int n)
{
    if(n == slen){
        result[slen] = 0;
        cout<<result<<endl;
        return ;
    }
    for(int i=0; i<slen; ++i){
        if(!used[i]){
            result[n] = s[i];
            used[i] = 1;
            permutation(n + 1);
            used[i] = 0;
        }
    }
}

int main() 
{
    cin>>s;
    slen = strlen(s);
    memset(result, 0, sizeof(result));
    //memset(used, 0, sizeof(used));
    //sort(s, s+1);
    //permutation(0);
    cout<<arra(result, slen)<<endl;
    return 0;
}*/

//#include <iostream>
//using namespace std;
 
/*void FullArray(char *str, int m, int len)
{
	int i;
 
	if (len == m)
	{
		for (i = 0; i < len; i++)
			cout << str[i];
		cout << endl;
	}
	else
	{
		for (i = m; i < len; i++)
		{
            swap(str[i], str[m]);
			FullArray(str, m + 1, len);
            swap(str[i], str[m]);
		}
	}
}
int main(void)
{
	char str[100];
    cin>>str;
	FullArray(str, 0, strlen(str));
	return 0;
}*/

void Permutation(char *str)
{
    int len=strlen(str);
    sort(str, str+len);
    do{
        cout<<str<<endl;
    }while(next_permutation(str, str + len));
}
int main()
{
    char str[10];
    cin>>str;
    Permutation(str);
    return 0;
}

bool permutation(char * str, int num)
{
    int i;
    for(i = num -2; (i >= 0) && (str[i] >= str[i+1]); --i) ;
    if(i < 0)
        return false;

    int k;
    for(k = num - 1; (k > i) && (str[k] >= str[i]); --k) ;
    swap(str[i], str[k]);
    reverse(str + i + 1, str + num);
    return true;
}