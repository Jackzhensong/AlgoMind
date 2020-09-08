#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T=12,d=0,f=0,k=0,sum=0;
    while(T--){
        int n;
        cin>>n;
        if(d>=0){ 
            sum+=(((d+300-n)/100)*100);  
            d=d+300-n-((d+300-n)/100)*100;        
            f++;
        }
        else 
            k=f;    
    }
    if(k)
        cout<<-k;
    else
        cout<<sum*1.2+d;
    return 0;
}