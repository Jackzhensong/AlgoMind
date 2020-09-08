#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k=0,f=-1,max=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        if(d>f){
            k++;
            if(k>max)
            max=k;
        }
        else k=1;
        f=d;
    }
    cout<<max;
    return 0;
}