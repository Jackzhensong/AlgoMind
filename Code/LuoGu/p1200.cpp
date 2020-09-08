#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10],b[10];
    int n=1,m=1;
    cin.getline(a,sizeof(a));
    cin.getline(b,sizeof(b));
    for(int i=0;a[i]!='\0';i++)
        n*=(a[i]-'A'+1);
    for(int i=0;b[i]!='\0';i++)
        m*=(b[i]-'A'+1);
    if(n%47==m%47)
        cout<<"GO";
    else cout<<"STAY";
        return 0;
}