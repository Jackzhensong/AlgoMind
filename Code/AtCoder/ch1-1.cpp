#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    int f=0,key=0;
    int x[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b<=t){
            x[f++]=a;
        }
        else key++;
    }
    int d=x[0];
    for(int i=1;i<f;i++){
        if(x[i]<d) d=x[i];
    }
    if(key==n)
    cout<<"TLE";
    else cout<<d;
    return 0;
}

const int inf{int(1e9)};
int main()
{
    int N,T;
    cin>>N>>T;
    int ans{inf};
    for(int i=0;i<N;i++){
        int c,t;
        cin>>c>>t;
        if(t<=T&&c<ans)
        ans=c;
    }
    if(ans==inf)
        cout<<"TIE";
    else cout<<ans;
    return 0;
}