#include<iostream>
using namespace std;

int fun(int x) {
    int num = 0;
    int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    while(x/10 != 0) {
        num += f[x%10];
        x /= 10;
    }
    num += f[x];
    return num;
}

int main() {
    int m, sum = 0;
    cin >> m;
    for(int a = 0; a <= 1111; ++a) {
        for(int b = 0; b <= 1111; ++b) {
            int c = a + b;
            if(fun(a) + fun(b) + fun(c) == m - 4) {
                cout << a << " + " << b << " = " << c << endl;
                sum++;
            } 
        }
    }
    cout << sum << endl;
    return 0;
}
