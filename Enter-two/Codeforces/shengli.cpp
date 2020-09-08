#include<bits/stdc++.h>  //生理周期
using namespace std;
#define N 21252
int main()
{
    int p,e,i,d;
    while(1){
        cin>>p>>e>>i>>d;
        if(p<0) break;
        else {
            int k;
            for(k=d+1; (k-p)%23; ++k) ;
            for( ; (k-e)%28; k+=23) ;
            for( ; ((k-i)%33 && (k<N)); k+= 23*28);
            cout<<k-d<<endl;
            }
    }
    return 0;
}