#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    int n;
    for(int i=0;i<k;i++){
        if(a%2==0){
            b+=a/2;
            n=a/2;a=b;b=n;
        }
        else{
            a-=1;
            b+=a/2;
            n=a/2;a=b;b=n;
        }
    }
    if(k%2==0) cout<<a<<" "<<b;
    else cout<<b<<" "<<a;
    return 0;
}