#include<bits/stdc++.h> //组合数排列
using namespace std;
int  a[25];
int sushu(int s){
    for(int i=2;i<=sqrt(s);i++){
        if(s%i==0) return 0;
    }
    return 1;
}
int rule(int num,int he,int begin,int end){  //生成全组合数排列
    if(num==0)  return sushu(he);
    int sum=0;
    for(int i=begin;i<=end;i++){
        sum+=rule(num-1,he+a[i],i+1,end);
    }
    return sum;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<rule(k,0,0,n-1);
    return 0;
}