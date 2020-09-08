#include<bits/stdc++.h>
using namespace std;

const int maxn=1001;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        char chara[maxn];
        int  str[26];
        memset(str,0,sizeof(str));
        memset(chara,0,sizeof(chara));
        cin>>chara;
        for(int j=0;chara[j]!='\0';++j){
            str[chara[j]-'a']++;
        }
    int big=0;
    for(int i=0;i<26;++i){
        if(str[i]>str[big])  big=i;
        }
        cout<<big<<endl;
    cout<<(char)(big+'a')<<" "<<str[big]<<endl;
    }
    return 0;
}