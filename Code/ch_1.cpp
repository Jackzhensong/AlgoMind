#include<bits/stdc++.h> //一元二次方程求解
using namespace std;
#define eps 1e-7
int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double n=b*b-4*a*c;
    if(n>-eps&&n<eps)
        printf("x1=x2=%.5f",(-b)/(2*a)+eps);
    else if(n>eps){
        double x1=(-b + sqrt(b*b-4*a*c))/(2*a);
        double x2=(-b - sqrt(b*b-4*a*c))/(2*a)+eps;
        if(x1-x2>eps)
        printf("x1=%.5f;x2=%.5f",x1+eps,x2+eps);
        else printf("x1=%.5f;x2=%.5f",x2+eps,x1+eps);
        }
    else {
        double shi=-b / (2*a); 
        double xu=sqrt(4*a*c-b*b) / (2*a);
        printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi",shi+eps,xu+eps,shi+eps,xu+eps);
    }
    return 0;
}