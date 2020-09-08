#include<bits/stdc++.h>
using namespace std;
char s[1000+5];
int main()
{
    double k1=0,k2=0,f=0;
    double sumleft=0,sumright=0;
    int len,i=0,num=0;
    cin>>s;
    char x;
    len=strlen(s)-1;
    while(i<=len)
    {
        while(s[i]=='+'||s[i]=='-'||i==0||s[i-1]=='=')
        {
            int ff=1;
            if(s[i]=='-') ff=-1;
            if(s[i+1]>='a'&&s[i+1]<='z') {
                num=-1;
                i++;
                break;
            }
            //else ff=1;
            if(s[i]>='a'&&s[i]<='z') {num=1;break;}
            num=0;    
            while(s[i]>='0'&&s[i]<='9')
            {
                num=(num*10)+s[i]-'0';
                i++;
            }
            num*=ff;
            break;
        }
            if(s[i]>='a'&&s[i]<='z')
            {
                x=s[i];
                if(f==0) k1+=num;
                else k2+=num;
                i++;
            }
            else
            {
                if(f==0) sumleft+=num;
                else sumright+=num;
            }
        if(s[i]=='=') 
        {
          f=1;
          i++;
       }
    }
    k1-=k2;
    sumright-=sumleft;
    double sum=sumright/k1;
    cout<<x<<"=";
    printf("%.3f", sum==0? abs(sum):sum);
    return 0;
}