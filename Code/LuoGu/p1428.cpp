#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=1;j<n;++j){
        int k=0;
        for(int i=0;i<j;++i)
            if(a[j]>a[i]) k++;    
        b[j]=k;
    }
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}