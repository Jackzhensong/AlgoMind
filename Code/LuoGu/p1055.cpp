#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char a[20],b[]="0123456789X";
    //a[20]={0};
    int d=1,s=0;
    cin.getline(a,sizeof(a));
    int L=strlen(a);
    for(int i=0;i<11;i++){
        if(a[i]=='-') continue;
        s+=(a[i]-'0')*d;
        d++;
    }
    if(b[s%11]==a[L-1])
    cout<<"Right";
    else {
        a[L-1]=b[s%11];
        for(int i=0;i<L;i++)
        cout<<a[i];
    }
    return 0;    
}