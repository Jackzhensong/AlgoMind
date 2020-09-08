#include<bits/stdc++.h>
using namespace std;
int main()
{
    int f=0,k=0,flag=1;
    char s[30],b[30];
    cin.getline(s,sizeof(s));
    int size=strlen(s);
    for(int i=0;i<size;i++){
        if(s[i]=='.'){
            if(s[0]=='0') cout<<0;
            else{
                for(int n=i-1;n>=0;n--){
                if(flag){
                    if(s[n]!='0') {
                    flag=0;
                    cout<<s[n]-'0';
                    }
                }
                    else cout<<s[n]-'0';
                }
            }
            flag=1;  
            cout<<'.';
            if(size==3) cout<<s[2]-'0';
            else{
                for(int j=i+1;j<size;j++){
                    if(flag){
                        if(s[j]!='0'){
                        flag=0;
                        b[k++]=s[j];
                        }
                    }
                    else b[k++]=s[j];
                }
                for(int d=strlen(b)-1;d>=0;d--)
                    cout<<b[d]-'0';
            }
            break;
        }
        else if(s[i]=='/'){
            if(s[0]=='0') cout<<0;
            else{
                for(int n=i-1;n>=0;n--){
                if(flag){
                    if(s[n]!='0'){
                    flag=0;
                    cout<<s[n]-'0';
                    }
                    }
                else  cout<<s[n]-'0';
                }
            }     
            flag=1;
            cout<<'/';
            for(int j=size-1;j>i;j--){
                    if(flag){
                        if(s[j]!='0'){
                        flag=0;
                        cout<<s[j]-'0';
                        }   
                    }
                    else cout<<s[j]-'0'; 
            } 
            break;
        }
        else if(s[i]=='%'){
            for(int j=size-2;j>=0;j--){
                    if(flag){
                        if(s[j]!='0'){
                        flag=0;
                        cout<<s[j]-'0';
                        }   
                    }
                    else cout<<s[j]-'0'; 
                }
            cout<<'%';
            break;
        }
        else f++;
    }
    if(f==size){
        if(s[0]=='0') cout<<0;
        else {
            for(int i=size-1;i>=0;i--){
            if(flag){
                if(s[i]!='0'){
                flag=0;
                cout<<s[i]-'0';
                }
            }
            else cout<<s[i]-'0';
        }
        }
    }
    return 0;
}