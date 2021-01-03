
/* 斐波那契数列 */
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int fib(int k) {
    int f1 = 1, f2 = 1, f;
    if(k == 1 || k == 2) return f1;
    else {
        for (int i = 2; i < k; ++i) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f;
    }
}

