#include<bits/stdc++.h>
using namespace std;

int chengfang(int n){
    long count=1;
    for(int i=0;i<n;++i)
        count*=2;
    return count-1;
}

int main(){
    while(1){
        long sum=0;
        char shu[32];
        cin>>shu;
        if(shu[0]=='0') break;
        else{
            int len=strlen(shu);
            int k=len;
            for(int i=0;i<k;++i){
                sum +=(shu[i]-'0')*chengfang(len);
                len--;
            }
        cout<<sum<<endl;
        }
    }
    return 0;
}

int main(){
    int base[31];
    char skew[32];
    base[0]=1;
    for(int i=1;i<31;++i){
        base[i]=2*base[i-1]+1;
    }
    while(1){
        cin>>skew;
        if(skew[0]=='0') break;
        int sum=0;
        int k=strlen(skew);
        for(int i=0;i<strlen(skew);++i){
            k--;
            sum+=(skew-'0')*base[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}