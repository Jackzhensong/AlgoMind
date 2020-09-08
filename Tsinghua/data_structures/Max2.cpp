
// 找出数组最大的两个数 A[x1], A[x2], A[x1] >= A[x2]

void Max2(int A[], int lo, int hi, int & x1, int & x2) {    // 区间 A[lo, hi)
    for (int i = lo + 1, x1 = lo; i < hi; ++i) 
        if (A[x1] < A[i]) x1 = i;
    for (int i = lo + 1, x2 = lo; i < x1; ++i) 
        if (A[x2] < A[i]) x2 = i;
    for (int i = x1 + 1; i < hi; ++i) 
        if (A[x2] < A[i]) x2 = i;
}

// 
void Max2(int A[], int lo, int hi, int & x1, int & x2) {    // 区间 A[lo, hi)
    if (A[x1 = lo ] < A[x2 = lo + 1]) swap(x1, x2);
    for (int i = lo + 2; i < hi; ++i) 
        if (A[x2] < A[i]) 
            if (A[x1] < A[x2 = i])
                swap(x1, x2); 
}

// 递归和分治
void Max2(int A[], int lo, int hi, int & x1, int & x2) {    // 区间 A[lo, hi)
    if (lo + 2 == hi) {
        if (A[x1 = lo] < A[x2 = lo + 1]) swap(x1, x2);
        return;
    }
    if (lo + 3 == hi) {
        if (A[x1 = lo] < A[x2 = lo + 1]) swap(x1, x2);
        if (A[x2] < A[lo + 2]) {
            x2 = lo + 2;
            if (A[x1] < A[x2]) swap(x1, x2);
        }
        return;
    }

    int mi = (lo + hi) >> 1;
    int x1L, x2L; 
    Max2(A, lo, mi, x1L, x2L);
    int x1R, x2R;
    Max2(A, mi, hi, x1R, x2R);

    if (A[x1L] > A[x1R]) {
        x1 = x1L;
        x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
    }
    else {
        x1 = x1R;
        x2 = (A[x1L] > A[x2R]) ? x1L : x2R;
    }
}