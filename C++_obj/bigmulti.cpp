#include<bits/stdc++.h>
using namespace std;

const int maxn=200;

char line1[maxn+10];
char line2[maxn+10];
unsigned  an1[maxn*2+10];

void reverse(char *p){
    int len=strlen(p);
    int i=0, j=len-1;
    while(i<=j){
        swap(p[i],p[j]);
        i++;
        j--;
    }
}

int main(){
    cin>>line1;
    cin>>line2;
    memset(an1,0,sizeof(an1));
    reverse(line1);
    reverse(line2);
    int len1=strlen(line1);
    int len2=strlen(line2);
    for(int i=0;i<len2;++i){
        for(int j=0;j<len1;++j)
        an1[i+j]+=(line2[i]-'0')*(line1[j]-'0');
    }

    int len=len1+len2;
    for(int i=0;i<len;++i){
        if(an1[i]>=10){
            an1[i+1]+=an1[i]/10;
            an1[i]%=10;
        }
    }
    bool flag=false;
    for(int i=len;i>=0;--i){
        if(flag){
            cout<<an1[i];
            continue;
        }
        if(an1[i]) {
            cout<<an1[i];
            flag=true;
        }
    }
    return 0;
}