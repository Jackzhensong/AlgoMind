#include<bits/stdc++.h>
using namespace std;
//输入一个子天平，返回子天平是否平衡，参数W修改为子天平的总重量
bool solve(int &w){
    int w1,d1,w2,d2;
    bool b1=true,b2=true;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) b1=solve(w1);
    if(!w2) b2=solve(w2);
    w=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}
int main()
{
    int T,W;
    cin>>T;
    while(T--){
        if(solve(W)) cout<<"YES\n";
        else cout<<"NO\n";
        if(T) cout<<endl;
    }
    return 0;
}