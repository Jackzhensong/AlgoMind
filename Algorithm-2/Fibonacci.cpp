
f[0] = f[1] = 1;
for(int i = 2; i <= n; ++i)   
    f[i] = -1;

int Fib(int n){
    if(f[n] != -1) 
        return f(n);
    f[n] = Fib(n - 1) + Fib(n - 2);
    return f[n];
}
