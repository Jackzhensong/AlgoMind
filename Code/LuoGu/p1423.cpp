#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
int main()
{
    double f,d=0,s=2;
    int k=0;
    cin>>f;
    while(f-d>eps){
        d+=s;
        s*=0.98;
        k++;
    }
    cout<<k;
    return 0;
}