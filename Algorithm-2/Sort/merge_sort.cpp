

#include <iostream>
using namespace std;


// 归并排序
void merge(int r[], int tmp[], int s, int m, int e) {  //归并过程
    int k = 0;
    int i = s, j = m + 1;

    while (i <= m && j <= e) {
        if (r[i] < r[j]) 
            tmp[k++] = r[i++];
        else 
            tmp[k++] = r[j++];
    }
    while (i <= m) tmp[k++] = r[i++];
    while (j <= e) tmp[k++] = r[j++];

    for (int i = 0; i <= e - s; i++) 
        r[s + i] = tmp[i];
}

void  mergesort(int A[], int T[], int s, int e) {
    if(s < e) {
        int m = (s + e) / 2;        // m = s + (e-s)/2;
        mergesort(A, T, s, m);
        mergesort(A, T, m+1, e);
        merge(A, T, s, m, e);
    }
}


int main() {
    int n;
    cin >> n;
    int A[n], T[n];
    for(int i = 0; i < n; i++) 
        cin >> A[i];
    mergesort(A, T, 0, n-1);
    for(int i = 0; i < n; i++) 
        cout << " " << A[i];
    return 0;
}


/*
// mergesort 
void merge_sort(int* A, int x, int y, int* T) {   // 左闭右开[x, y)
    if(y - x > 1) {
        int m = x + (y - x) / 2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while(p < m || q < y) {       // [x, m) && [m, y)
            if(q >= y || (p < m && A[p] <= A[q])) 
                T[i++] = A[p++];
            else T[i++] = A[q++];
        }
        for(int i = x; i < y; ++i) A[i] = T[i];
    }
}


// 逆序对
int cnt = 0;    // cnt 逆序对变量
void merge_sort(int* A, int x, int y, int* T) {   // 左闭右开[x, y)
    if(y - x > 1) {
        int m = x + (y - x) / 2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while(p < m || q < y) {        // [x, m) && [m, y)
            if(q >= y || (p < m && A[p] <= A[q])) 
                T[i++] = A[p++];
            else {
                T[i++] = A[q++];
                cnt += m - p;   // 关键语句
            }
        }
        for(int i = x; i < y; ++i) A[i] = T[i];
    }
}
*/