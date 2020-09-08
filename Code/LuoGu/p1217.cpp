#include<bits/stdc++.h>
using namespace std;

const int  M=100000;
int sushu(int t){
    int f=sqrt(t);
    for(int i=2;i<=f;i++)
        if(t%i==0) return 0;
    return 1;
}
/*int huiwen(int shu){
    int k=shu,d=0;
    while(k){
        d=d*10+k%10
        k/=10;
    }
    if(d==shu) return 1;
    else return 0;
}*/
/*int weishu(int  n){
    int f=0;
    while(n){
        n/=10;
        f++;
    }
    return f;
}*/

int main()
{
    int  a,b;
    cin>>a>>b;
    int  s[M];
    int k=3;
    s[0]=5;s[1]=7;s[2]=11;
    for(int i=3;i<=7;i+=2){
        switch (i)
        {
            case 3:{
                for(int d1=1;d1<=9;d1+=2)
                    for(int d2=0;d2<=9;d2++){
                        int  pal=d1*100+d2*10+d1;
                        if(sushu(pal)) s[k++]=pal;
                    }
                    break;
            }
            case 5:{
                for(int d1=1;d1<=9;d1+=2)
                    for(int d2=0;d2<=9;d2++){
                         for(int d3=0;d3<=9;d3++){
                             int pal=d1*10000+d2*1000+d3*100+d2*10+d1;
                            if(sushu(pal)) s[k++]=pal;
                         }
                    }
                    break;
            }
            case 7:{
                for(int d1=1;d1<=9;d1+=2)
                    for(int d2=0;d2<=9;d2++){
                         for(int d3=0;d3<=9;d3++){
                             for(int d4=0;d4<=9;d4++){
                             int pal=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
                             if(sushu(pal))  s[k++]=pal;
                             }
                         }
                    }
                    break;
                }
            }
        }
        for(int i=0;i<=k;i++){
            if(s[i]>=a&&s[i]<=b) cout<<s[i]<<endl;
        }
        return 0;
}