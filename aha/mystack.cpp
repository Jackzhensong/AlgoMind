#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100;

int main() {
    char a[maxn], s[maxn];
    cin >> a;
    int len = strlen(a);
    int mid = len / 2 - 1;
    int top = 0;
    for(int i = 0; i <= mid; ++i) 
        s[++top] = a[i];
    int next;
    next = (len % 2 == 0) ? mid + 1 : mid + 2;
    for(int i = next; i < len; ++i) {
        if(a[i] != s[top]) break;
        top--;
    }
    if(top == 0) cout << "YES";
    else cout << "NO";
    return 0;
}

