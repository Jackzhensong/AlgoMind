#include<bits/stdc++.h>    //逆波兰表达式
using namespace std;
double exp()
{
    char s[20];
    cin>>s;
    switch (s[0]){
        case '+': return exp() + exp();
        case '-': return exp() - exp();
        case '*': return exp() * exp();
        case '/': return exp() / exp();
        default: return stof(s);
        break;
    }
}
int main(){
    printf("%lf", exp());
    return 0;
}
