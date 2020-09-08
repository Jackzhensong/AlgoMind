#include<bits/stdc++.h>  //找鞍点
using namespace std;
#define n 5
#define m 5
int main()
{
    int max,key=1;
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    for(int i=0;i<n;i++){
        max=a[i][0];
        int flag=0;
        int x=i;
        int y=0;
        for(int j=1;j<m;j++)
            if(a[i][j]>max){
            max=a[i][j];
            y=j;
        }
        for(int k=0;k<n;k++){
            if(a[k][y]<max)  break;
            else flag++;
        }
        if(flag==5)    
           { cout<<x+1<<" "<<y+1<<" "<<max;
           key=0;}
    }
    if(key)   
         cout<<"not found"; 
    return 0;   
}