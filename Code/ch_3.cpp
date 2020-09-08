#include<bits/stdc++.h> //四则运算
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    char d,f;
    scanf("%c%c",&d,&f);
    switch (f)
    {
        case '+':
            cout<<a+b;break;
        case '-':
            cout<<a-b;break;
        case '*':
            cout<<a*b;break;
        case '/':
            {
                if(b==0) printf("Divided by zero!");
                else cout<<a/b;
                }
                break;
        default:
            printf("Invalid operator!");
            break;
    }
    return 0;
}