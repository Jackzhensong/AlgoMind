
int pow(int a, int b)   //快速幂 a^b
{  
    if(b==0)    return 1;
    if(b%2==1) {
        return a*pow(a,b-1);
    }
    else{
        int t=pow(a,b/2);
        return t*t;
    }
}

int pow(int a, int b){
    int result=1;
    int base=a;
    while(b){
        if(b%2==1)  result*=base;
        base*=base;
        b/=2;
    }
    return result;
}