#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    int num[10];
    while(t--) {
        cin >> n;
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; ++i) {
            int k = i;
            while(k) {
                ++num[k % 10];
                k /= 10;
            }
        }
        for(int i = 0; i < 9; ++i) 
            printf("%d ", num[i]);
        printf("%d\n", num[9]);
    }
    return 0;
}