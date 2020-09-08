#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 100;
int a[maxn], book[maxn], total = 0;

void dfs(int step) {
    if(step == 10) {
        if(a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9]) {
            total++;
            cout << a[1]<<a[2]<<a[3] << " + " << a[4]<<a[5]<<a[6] << " = " <<a[7]<<a[8]<<a[9] << endl;
        }
    }
    for(int i = 1; i <= 9; ++i) {
        if(book[i] == 0) {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}

int main() {
    dfs(1);
    cout << total / 2;
    return 0;
}