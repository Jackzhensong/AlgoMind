#include<bits/stdc++.h>     //最小公约数
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b){
        int t=a;
        a=b; b=t;
    }
    while(a%b){
        int k=a;
        a=b;
        b=k%b;
    }
    cout<<b;
    return 0;
}