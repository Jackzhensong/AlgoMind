#include<iostream>
#include<algorithm>
using namespace std;

int findk(int a[], int s, int e, int k) {
    if(s > e) return 0;
    int val = a[s];
    int i = s, j = e;
    while(i != j) {
        while(i < j && a[j] >= val) --j;
        swap(a[i], a[j]);

        while(i < j && a[i] <= val) ++i;
        swap(a[i], a[j]);
    }
    if(k == i + 1) return a[i];
    else if(k < i+1) findk(a, s, i-1, k);
    else if(k > i+1) findk(a, i+1, e, k);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i =0; i < n; ++i) 
        cin >> a[i];
    int k;
    cin >> k;
    cout << findk(a, 0, n-1, k) << endl;
    return 0;
}