#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f=0;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            int d=a[i]+a[j];
            for(int k=0;k<n;k++){
            if(b[k]==d){
                f++;
                b[k]=0;     //去重，应为1+4=5和2+3=5算重复
                break;
                }
            }
        }
    cout<<f;
    return 0;
}