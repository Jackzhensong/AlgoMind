#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    int a[n + 10];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; ++i) {
        cin >> num;
        a[num]++;
    }
    for(int i = 0; i < n + 10; ++i)
        for(int j = 1; j <= a[i]; ++j)
            cout << i <<" ";
    return 0;
}  