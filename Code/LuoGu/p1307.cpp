#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int flag=1;
    if(n>0){
        while(n){
            if(flag){
                if(n%10)  {cout<<n%10;flag=0;}
            }
            else cout<<n%10;
            n/=10;
        }
    }
    else if(n<0){
        n=-n;
        while(n){
            if(flag){
                if(n%10) {cout<<-n%10;flag=0;}
            }
            else cout<<n%10;
            n/=10;
        }
    }
    return 0;
}