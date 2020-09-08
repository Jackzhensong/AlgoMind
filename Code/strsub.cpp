#include<bits/stdc++.h>
using namespace std;
int  t,n;
char str[100][100];

int search_maxstr(char* source){
    int substrlen=strlen(source), sourcestrlen=strlen(source);
    bool foundmaxstr;
    char substr[101], revsubstr[101];
    while(substrlen>0){
        for(int i=0;i<=sourcestrlen-substrlen;++i){
            strncpy(substr,source+i,substrlen);
            strncpy(revsubstr,source+i,substrlen);
            substr[substrlen]=revsubstr[substrlen]='\0';
            strrev(revsubstr);
            foundmaxstr=true;
            for(int j=0;j<n;++j)
            if(strstr(str[j],substr)==NULL&&strstr(str[j],revsubstr)==NULL){
                foundmaxstr=false;
                break;
            }
            if(foundmaxstr) return (substrlen);
        }
        substrlen--;
    }
    return 0;
}

int main(){
    int i,minstrlen,substrlen;
    char minstr[101];
    cin>>t;
    while(t--){
        cin>>n;
        minstrlen=100;
        for(int i=0;i<n;++i){
            cin>>str[i];
            if(strlen(str[i])<minstrlen){
                strcpy(minstr,str[i]);
                minstrlen=strlen(minstr);
            }
        }
        substrlen=search_maxstr(minstr);
    }
    return 0;
}