#include<bits/stdc++.h>
using namespace std;

const int a[]={6,2,5,5,4,5,6,3,7,6};
int dg(int s){
    int d=0;
    if(s==0) return a[0];
    else{
        while(s){
        d+=a[s%10];
        s/=10;
        }
    }
    return d;
    }
int main()
{
    int n;
    cin>>n;
    int f=0;
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++){
            if((dg(i)+dg(j)+dg(i+j)==n-4)) 
                f++;
    }
    cout<<f;
    return 0;
}