#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int f=a[x];
    int d,sum=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==f) {d=i;break;}
    }
    if(d==n) cout<<0;
    else {
        for(int i=d;i<n;i++){
            int k=a[i+1]-a[i];
            sum+=k+(n-i-1)*k;
        }
        cout<<sum+n-d;
    }
    return 0;  
}