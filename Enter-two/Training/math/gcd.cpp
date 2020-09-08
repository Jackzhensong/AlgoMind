#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", gcd(n, m));
    return 0;
}


/// fraction ///
struct Fraction {
    int down, up;
};

Fraciton reduction(Fraciton result){
    if(result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0) {
        result.down = 1;
    }
    else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

//// fraction additon ///
Fraciton add(Fraction f1, Fraciton f2) {
    Fraciton result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

void showResult(Fraciton r) {
    r = reduction(r);
    if(r.down == 1) printf("%lld", r.up);
    else if(abs(r.up) > r.down) {
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
    }
    else printf("%d/%d", r.up, r.down);
}