#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int d=y/x;
    if(y%x)
        d++;
    if(n>=d)
    cout<<n-d;
    else cout<<0;
    return 0;
}