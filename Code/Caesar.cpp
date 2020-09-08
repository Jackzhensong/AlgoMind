#include<bits/stdc++.h>
using namespace std;

void decode(char *message){
    char p[27]="VWXYZABCDEFGHIJKLMNOPQRSTU";
    char s[201];
    int slen;
    cin.getline(message,201);
    slen=strlen(message);
    for(int i=0;i<slen;++i){
        if(message[i]>='A' && message[i]<='Z') 
            message[i]=p[message[i]-'A']+32;      
    }
    cin.getline(s,201);
    return;
}

int  main(){
    char message[201];
    cin.getline(message,201);
    while(strcmp(message,"START")==0){
        decode(message);
        cout<<message<<endl;
        cin.getline(message,201);
    }
    return 0;
}