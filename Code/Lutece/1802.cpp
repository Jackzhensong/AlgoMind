#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int a,b,c,k1=0,k2=0,k3=0;
    int sum,count1,count2;
    int s1[n],s2[n],d[n];
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if((a!=0)&&(b<=x)&&(c<=y)) {
            d[++k1]=a;
            s1[++k2]=b;
            s2[++k3]=c;
        }
    }
    int f=0;
    for(int i=1;i<=k1;i++){
        sum=d[i];count1=s1[i];count2=s2[i];
        for(int j=i+1;j<=k1;j++){
            if(count1+s1[j]<=x && count2+s2[j]<=y){
                count1+=s1[j];
                count2+=s2[j];
                sum+=d[j];
            } 
        }
        if(sum>f) f=sum;
    }
    cout<<f;
    return 0;
}