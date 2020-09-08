#include<iostream>
#include<algorithm>
using namespace std;

inline void Quicksort(int a[], int s, int e){
    if(s >= e)  return;
    int i = s; 
    int j = e;
    int k = a[s];
    while(i != j){
        while(i < j && a[j] >= k) 
            j--;
        swap(a[i], a[j]);
        while(i < j && a[i] <= k)
            i++;
        swap(a[i], a[j]);
    }
    Quicksort(a, s, i - 1);
    Quicksort(a, i + 1, e);
}
const int maxn = 100000 + 10;
int a[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    Quicksort(a, 0, n - 1);
    for(int i = 0; i < n; ++i){
        cout<<a[i];
        if(i < n - 1) cout<<" ";
    }
    return 0;
}