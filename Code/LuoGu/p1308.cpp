#include<bits/stdc++.h>
using namespace std;
const int N=15;
const int M=1000000;
int main()
{
    int d=0,k,flag=1,f=0;
    char s1[N],s2[M],a[N];
    cin.getline(s1,sizeof(s1));
    cin.getline(s2,sizeof(s2));
    int h=strlen(s1),g=strlen(s2);
    for(int i=0;i<h;i++)
        s1[i]=tolower(s1[i]);
    for(int i=0;i<g;i++)
        s2[i]=tolower(s2[i]);
    for(int i=0;i<=g;i++){
        if(s2[i]!=' '&&s2[i]!='\0')
            a[f++]=s2[i];
        if(s2[i]==' '||s2[i]=='\0'){
            if(strcmp(s1,a)==0){   
                d++;
                if(flag) k=i-h;
                flag=0;
            }
            memset(a,0,sizeof(a));
            f=0;
        }
    }
        if(d) cout<<d<<" "<<k;
        else cout<<-1;
        return 0;
}