#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1010],b[1010];
    while(cin>>a>>b){
    int m=strlen(a);
    int n=strlen(b);
    int kase=0,d=0;
    for(int i=0;i<m;i++){
        for(int j=d;j<n;j++){
            if(a[i]==b[j]){
                kase++;
                d=j+1;
                break;
            }    
        }
    }
    cout<<kase;
    } 
    return 0;
}

