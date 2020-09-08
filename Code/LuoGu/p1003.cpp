#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
int arra[maxn][4];
int main(){
    int n,f=1;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>arra[i][0]>>arra[i][1]>>arra[i][2]>>arra[i][3];
        arra[i][2]+=arra[i][0];
        arra[i][3]+=arra[i][1];
    }
    int x,y;
    cin>>x>>y;
    for(int i=n;i>=1;--i){
        if(arra[i][0]<=x&&arra[i][1]<=y&&arra[i][2]>=x&&arra[i][3]>=y){
            cout<<i;
            f=0;
            break;
        }
    }
    if(f) cout<<-1;
    return 0;
}