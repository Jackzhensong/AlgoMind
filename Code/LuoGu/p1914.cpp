#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[55];
    int n;
    cin>>n;
    cin>>s;
    int k=strlen(s);
    for(int i=0;i<k;i++){
        if(s[i]+n>'z')
        s[i]='a'+(s[i]+n-'z'-1);
        else s[i]=s[i]+n;
    }
    for(int i=0;i<k;i++)
    cout<<s[i];
    return 0;
}