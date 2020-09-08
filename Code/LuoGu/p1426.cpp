#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,x,t;
    cin>>s>>x;
    double s1=7.0,sum=0;
    for(t=0; ;t++){
        sum+=s1;
        s1*=0.98;
        if(sum>=(s-x)){
            if(sum+s1<=s+x) cout<<'y';
            else cout<<'n';
            break;
        } 
    }
    return 0;
}