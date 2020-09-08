#include <cstdio>
#include <cmath>
using namespace std;

int factorial(int n) {
    long a[10000];
    int m = 0;
    a[0] = 1;

    for(int i = 1; i <= n; ++ i) {
        int c = 0;
        for(int j = 0; j <= m; ++ j) {
            a[j] = a[j] * i + c;
            c = a[j] / 10000;
            a[j] = a[j] % 10000;
        }
        if(c > 0) { 
            m ++;
            a[m] = c;
        }
    }

    int w = m * 4 + log10(a[m]) + 1;
    printf("\n%ld", a[m]);
    for(int i = m-1; i >= 0; i --) printf("%4.4ld", a[i]);
    return w;
}

int main() {
    int n;
    scanf("%d", &n);
    int ans = factorial(n);
    printf("\n%d", ans);
    return 0;
}