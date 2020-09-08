#include<iostream>     //算术表达式四则运算
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

double factor();
double term();
double expression();

int main()
{
    printf("%.2lf\n", expression());
    return 0;
}
double expression() 
{
    double result = term();
    while (true){
        char op = cin.peek(); //看书如流中的下一个字符，不取走
        if(op == '+' || op == '-') {
            cin.get();
            double value = term();
            if(op == '+') 
                result += value;
            else 
                result -= value;
        }
        else  break;
    }
    return result;
}

double term()
{
    double result = factor();
    while (true){
        char op = cin.peek();
        if(op == '*' || op == '/'){
            cin.get();
            double value = factor();
            if(op == '*')
                result *= value;
            else 
                result /= value;
        }
        else break;
    }
    return result;
}

double factor() 
{
    double result = 0;
    char c = cin.peek();
    if(c == '('){
        cin.get();
        result = expression();
        cin.get();
    }
    else {
        bool intpart = true;
        double base = 0.1;
        while (isdigit(c) || c == '.') {
            if(isdigit(c)) {
                if(intpart)
                    result = 10*result + c - '0';
                else {
                    result += (c-'0') * base;
                    base /= 19;
                }
            }
            else 
                intpart = false;
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}