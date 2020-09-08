#include<bits/stdc++.h>
using namespace std;
int sushu(int s){
    for(int i=2;i<=sqrt(s);i++)
        if(s%i==0) {return 0; break;}
    return 1;   
}
int main()
{
    int a[20000];
    int d=0,n;
    cin>>n;
    for(int i=2;i<20000;i++){
        if(sushu(i)) a[d++]=i;
    }
    int f=0;
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<d;k++){
                if(a[i]+a[j]+a[k]==n){
                printf("%d %d %d",a[i],a[j],a[k]);
                f=1;
                break;
                }
            }
            if(f) break;
        }
        if(f) break;
    }
    return 0;
}