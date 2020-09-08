#include <bits/stdc++.h>  // 反转单词

using namespace std;

int main() {
    string s;
    int flag = 1;
    getline(cin, s);
    int len = s.length();
    string ch, str;
    for(int i = 0; i <= len; ++i) {        
        if(s[i] == ' ' || s[i] == '\0') {
            reverse(ch.begin(), ch.end());
            str += ch;
            if(flag == 1) {
                str += ' ';
                flag = 0;
            }
            ch = {0};
        }
        else ch += s[i];
    }
    cout << str;
    return 0;
}
