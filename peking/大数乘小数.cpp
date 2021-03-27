#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 10000;
char c[maxn], t[maxn];
int m;

void mult(char c[], char t[], int m) {
    int flag, i, k, len, add = 0;
    char s[100];
    len = strlen(c);

    for(i = 0; i < len; ++ i) s[len - i - 1] = c[i] - '0';
    for(i = 0; i < len; ++ i) {
        k = s[i] * m + add;
        if(k >= 10) {
            s[i] = k % 10; 
            add = k / 10;
            flag = 1;
        } 
        else {
            s[i] = k;
            flag = 0;
            add = 0;
        }
    }
    if(flag != 0) {
        len = i + 1;
        s[i] = add;
    }
    else len = i;

    for(i = 0; i < len; ++ i) 
        t[len - 1 - i] = s[i] + '0';
        t[len] = '\0';
}


int main() {
    cin >> c;
    cin >> m;
    mult(c, t, m);
    cout << t << endl;
    return 0;
}

/// 大数乘大数 ///
