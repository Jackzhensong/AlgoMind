#include<bits/stdc++.h>
using namespace std;

long b2ten(char* x,int b){
    int ret=0;
    int len=strlen(x);
    for(int i=0;i<len;++i){
        if(x[i]-'0'>=b) return -1;
        ret *=b;
        ret+=x[i]-'0';
    }
    return (long)ret;
}

int main(){
    int n;
    char p[8],q[8],r[8];
    cin>>n;
    long pal,qal,ral;
    while(n--){
        int f=1;
        cin>>p>>q>>r;
        for(int b=2;b<=16;++b){
            pal=b2ten(p,b);
            qal=b2ten(q,b);
            ral=b2ten(r,b);
            if(pal==-1||qal==-1||ral==-1) continue;
            if(pal*qal==ral){
                cout<<b<<endl;
                f=0;
                break;
            }
        }
        if(f) cout<<0<<endl;
    }
    return 0;
}