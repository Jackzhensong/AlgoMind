#include<bits/stdc++.h>
using namespace std;

long zdgr(long a,long b)    //求最大公约数
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b){
        long tmp=a;
        a=b;
        b=tmp;
    }
    if(b==0) return a;
    while(a%b){
        long tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}

long zdgb(long m,long n)    //求最小公倍数
{
    if(n==0)    return m;
    return m*n/zdgr(m,n);
}

int main()
{
    long a,b;
    cin>>a>>b;
    cout<<zdgr(a,b)<<endl;
    cout<<zdgb(a,b);
    return 0;
}