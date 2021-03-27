

void ReverseStr(char *s, int from, int to) {
    while (from < to) {
        char ch = s[from];
        s[from++] = s[to];
        s[to--] = ch;
    }
}

void LeftRotateStr(char *s, int n, int m) {
    m %= n;
    ReverseStr(s, 0, n-1);
    ReverseStr(s, 0, m-1);
    ReverseStr(s, m, n-1);
}