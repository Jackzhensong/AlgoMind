#include<bits/stdc++.h>
using namespace std;

void count(int num,int *addAll,int *mulAll){
    int i = num/100;   //百位数
    int j = num/10%10; //十位数
    int k = num%10;    //个位数
    (*addAll) += i+j+k;
    (*mulAll) *= i*j*k;
    return;
}
int main()
{
    //至少3位数，百位数最少是1，数字不得重复得最少为123
    //同理 最大为987根据比例得 i最大为987/3
    int f=1;
    int a,b,c;
    cin>>a>>b>>c;
    //int  d1=b/a,d2=c/a;
    for(int i = 123; i <=987/3; i++)
    {
        int addAll=0;
        int mulAll=1;
        count(  i, &addAll, &mulAll);
        count(i*b/a, &addAll, &mulAll);
        count(i*c/a, &addAll, &mulAll);
        //1-9的和只能是 9*10/2
        //1-9的积只能是 2*3*4*5*6*7*8*9
        if(addAll == 9*10/2 && mulAll == 2*3*4*5*6*7*8*9){
            printf("%d %d %d\n", i, i*b/a, i*c/a);
            f=0;
            }
    }
    if(f) cout<<"No!!!";
    return 0;
}