#include<bits/stdc++.h>
using namespace std;

const int maxn=200;

char an1[maxn+10];
char line1[maxn+10];
char line2[maxn+10];

void reverse(char *p){
    int len=strlen(p);
    int i=0, j=len-1;
    while(i<=j){
        swap(p[i],p[j]);
        i++;
        j--;
    }
}

int main( ) {
    memset(line1,0,sizeof(line1));
    memset(line2,0,sizeof(line2));
    memset(an1,0,sizeof(an1));

    cin >> line1;
    cin >> line2;
    reverse(line1);
    reverse(line2);
    
    int carry=0;
    for(int i=0;i<maxn;++i){
        char c1=line1[i];
        char c2=line2[i];
        if(c1==0&&c2==0&&carry==0) break;
        if(c1==0) c1='0';
        if(c2==0) c2='0';
        int k=c1-'0'+c2-'0'+carry;
        if(k>=10) {
            carry=1;
            an1[i]=k-10+'0';
        }
        else{
            carry=0;
            an1[i]=k+'0';
        }
    }
    int len=strlen(an1);
    for(int i=len-1;i>=0;--i)
        cout<<an1[i]-'0';
    return 0;
}