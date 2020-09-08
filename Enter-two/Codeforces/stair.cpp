#include<iostream>     //走楼梯问题
using namespace std;

int stair(int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    return stair(n-1) + stair(n - 2);
}
int main()
{
    int N;
    while(cin>> N){
        cout<<stair(N)<<endl;
    }
    return 0;
}