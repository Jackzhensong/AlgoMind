
#include <bits/stdc++.h>
using namespace std;


int hailstone(int n) {
    int length = 1;
    while (1 < n) {
        (n % 2) ? n = 3 * n + 1 : n /= 2;
        length++;
    }
    return length;
}

// 起泡排序
void bubblesort(int A[], int n) {
    for (bool sorted = false; !sorted; n--) {
        sorted = true;
        for (int i = 1; i < n; ++i) 
            if(A[i-1] > A[i]) {
                swap(A[i-1], A[i]);
                sorted = false;
            }
    }
}

// 数组求和
int Sum(int A[], int n) {
    return (n < 1) ? 0 : Sum(A, n-1) + A[n-1];
}

// 数组求和：二分递归
int Sum2(int A[], int lo, int hi) {     // 区间范围 A[lo, hi]
    if (lo == hi) return A[lo];
    int mi = (lo + hi) >> 1;
    return Sum2(A, lo, mi) + Sum2(A, mi + 1, hi);
}   // 入口形式 Sum2(A, 0, n-1)


// 数组倒置
void Reverse(int *A, int lo, int hi) {
    // recurse 
    if (lo < hi) {
        swap(A[lo], A[hi]);
        Reverse(A, lo + 1, hi - 1);
    }

    // iterated 
    while (lo < hi) swap(A[lo++], A[hi--]);
}


