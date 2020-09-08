#include<bits/stdc++.h> //石头剪刀布
using namespace std;

int main()
{
    int n;
    cin>>n;
    char s1[10],s2[10];
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        if(strcmp(s1,"Rock")==0){
            if(s2[0]=='P') cout<<"Player2"<<endl;
            else if(s2[0]=='S') cout<<"Player1"<<endl;
            else cout<<"Tie"<<endl;
        }
        if(strcmp(s1,"Scissors")==0){
            if(s2[0]=='P') cout<<"Player1"<<endl;
            else if(s2[0]=='R') cout<<"Player2"<<endl;
            else cout<<"Tie"<<endl;
        }
        if(strcmp(s1,"Paper")==0){
            if(s2[0]=='S') cout<<"Player2"<<endl;
            else if(s2[0]=='R') cout<<"Player1"<<endl;
            else cout<<"Tie"<<endl;
        }
    }
    return 0;
}