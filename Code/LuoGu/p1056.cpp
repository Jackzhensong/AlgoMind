#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[2500]={};
    int a1[2500]={};
    int b[2500]={};
    int b1[2500]={};

    int M,N,K,L,D;
    int x1,x2,y1,y2;

    cin>>M>>N>>K>>L>>D;
    for(int i=1; i<=D; i++)
    {
    cin>>x1>>y1>>x2>>y2;
    if (x1 != x2) {
            if (x1 > x2)  b[x2]++;
            else b[x1]++;        
        } 
    else if(y1 > y2)  a[y2]++;
    else a[y1]++;
    }
    int max=0,x=0;
    for(int i=1;i<=K;i++)
    {
        max=0;
        x=0;
        for(int j=1;j<=M;j++){
          if (b[j]>max) 
            max=b[j], x=j;
        }
        a1[i]=x;
        b[x]=0;
    }

    for(int i=1;i<=L;i++)
    {
        max=0;
        x=0;
        for(int j=1;j<=N;j++)
          if (a[j]>max) max=a[j], x=j;
        b1[i]=x;
        a[x]=0;
    }
    sort(a1,a1+K+1);
    for(int i=1;i<=K;i++)
      printf("%d ",a1[i]);
    cout<<endl;
    sort(b1,b1+L+1);
    for(int i=1;i<=L;i++)
      printf("%d ",b1[i]);
    return 0;
}