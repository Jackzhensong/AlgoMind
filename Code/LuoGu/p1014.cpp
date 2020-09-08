#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,count,reg;
    cin>>n;
    for(int i=n/2;i>0;--i){
        int sum=(1+i)*i/2;
        if(sum<=n){
            reg=i;
            count=n-sum;
            break;
        } 
    }
    if (n==1) cout<<"1/1"<<endl;
    else if(reg%2) {
        if(count==0) cout<<1<<"/"<<reg<<endl;
        else cout<<count<<"/"<<(reg+2)-count<<endl;
    }
    else {
        if(count==0) cout<<reg<<"/"<<1<<endl;
        else cout<<(reg+2)-count<<"/"<<count<<endl;
    }
}