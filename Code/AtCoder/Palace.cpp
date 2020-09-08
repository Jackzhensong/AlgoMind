#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,T,A;
    double d=1e6;
    int f=0;
    cin>>N>>T>>A;
    for(int i=1;i<=N;i++){
        double h;
        cin>>h;
        double val=fabs(A-(T-h*0.006));
        if(val<d) {d=val;f=i;}
    }
    cout<<f;
    return 0;
}
