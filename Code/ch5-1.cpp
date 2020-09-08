#include<bits/stdc++.h> //数轴植树区域交叠问题
using namespace std;
const int  maxn=10005
int main()
{
    int a[maxn];
    int L,M;
    cin>>L>>M;
    for(int i=0;i<=L;++i)
        a[i]=1;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        for(int j=x;j<=y;j++)
            a[j]=0;
    }
    int s=0;
    for (int i=0;i<=L;i++)
        s+=a[i];
    cout<<s;
    return 0;
}