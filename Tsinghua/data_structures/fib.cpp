

int fib(int n) {
    int f = 0;
    int g = 1;
    if (n == 0) return 0;
    while(1 < n--) {
        g = g + f;
        f = g - f;
    }
    return g;
}