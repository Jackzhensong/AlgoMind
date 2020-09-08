#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
        int a;
        cin>>a;
        if(a%2||a==0) 
            cout<<"0 0"<<endl;
        else {
            if(a==2) {cout<<1<<" "<<1;}
            else {cout<<a/4<<" "<<a/2;}
        }
    }
    return 0;
}