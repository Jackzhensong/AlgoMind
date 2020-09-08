#include<iostream>      //输出前n大的值
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void arrangeRight(int a[], int s, int e, int f, int b[]){
    int k = a[s];
    int i = s, j=e;
    int key = 0;
    while(i!=j){
        while(i < j && k < a[j])
            --j;
        swap(a[i], a[j]);
        while(i < j && a[i] < k)
            ++i;
        swap(a[i], a[j]);
    }
    int tmp = e - i + 1;
    if(tmp > f) arrangeRight(a, i+1, e, f, b);
    if(tmp < f) arrangeRight(a, s, i-1, f - (e - i +1), b);
    if(tmp == f) {
        for(int d =i; d <=e ; ++d){
            b[key++] = a[d];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    arrangeRight(a, 0, n-1, m, b);
    sort(b, b+m);
    for(int i=m-1; i>=0; --i)
        cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}