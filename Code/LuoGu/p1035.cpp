#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
int main()
{
    int k,n;
    double s=0;
    cin>>k;
    for(int i=1; ;i++){
        s+=1.0/i;
        if((s-k)>eps) {n=i; break;}
    }
    cout<<n;
    return 0;
}