#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 100;
char s[maxn];

int judge(char s[], int t, int len) {
    for(int i = 0; i < len && i + t < len; ++i) {
        if(s[i] != s[i + t]) return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        cin >> s;
        int len = strlen(s);
        for(int i = 1; i <= len; ++i) {     // 枚举，假设周琪为 i
            if(len % i != 0) continue;
            if(judge(s, i, len)) {
                cout << i << endl;
                break;
            }
        }
        if(n) cout << endl;
    }
    return 0;
}