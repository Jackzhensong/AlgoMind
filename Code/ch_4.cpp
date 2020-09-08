#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
int main()
{
    int n,s,f;
    cin>>n;
    cin>>s>>f;
    double x=(double)f/s;
    while(--n){
        int a,b;
        cin>>a>>b;
        double y=(double)b/a;
        if(y-x-0.05>eps) cout<<"better"<<endl;
        else if(x-y-0.05>eps) cout<<"worse"<<endl;
        else cout<<"same"<<endl;
    }
    return 0;
}