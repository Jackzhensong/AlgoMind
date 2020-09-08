#include <bits/stdc++.h> // 字符串去重

using namespace std;

const int maxn = 10010;
void remove(char *s, int n) {
    char as[maxn] = {0};
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(as[s[i]] == 0) 
            s[k++] = s[i];
        as[s[i]] = 1;
    }
    s[k] = '\0';
}

int main() {
    char str[maxn];
    cin >> str;
    int len = strlen(str);
    remove(str, len);
    cout << str;
    return 0;
}

