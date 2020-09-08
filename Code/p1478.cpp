#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    int a,b;
    int d=0,k=0,f[5000];
    cin>>n>>s;
    cin>>a>>b;
    int h=a+b;
    for(int i=0;i<n;i++){
        int x,yi;
        cin>>x>>yi;
        if(x>h) continue;
        else f[k++]=yi;
    }
    int sum=0;
    sort(f,f+k);
    for(int i=0;i<k;i++){
        sum+=f[i];
        if(sum<=s) d++;
        else break;
    }  
    cout<<d;
    return 0;
}