#include<bits/stdc++.h> //找第一个只出现一次的字符
using namespace std;

const int  maxn=100000
char a[maxn];

int main()
{
    cin>>a;
    int k;
    int L=strlen(a);
    for(int i=0;i<L;i++) {
        k=0;
        for(int j=0;j<L;j++) {
            if(a[i]==a[j])  k++;
            if(k>1) break;
        }
        if(k==1) { cout<<a[i]; break; }
    }
    if(k!=1)
    cout<<"no";
    return 0;
}