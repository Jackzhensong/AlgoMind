#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n,sum=0;
    cin>>x>>n;
    int k=x;
    for(int i=0;i<n;i++){
        if(k>=7) k=0;
        else if(k<=5)
            sum+=250;
        k++;
    }
    cout<<sum;
    return 0;
}