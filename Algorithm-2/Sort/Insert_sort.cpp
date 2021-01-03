
// 简单插入排序,稳定排序
void insertsort(int A[], int size) {
    for (int i = 1; i < size; i++) {
        if (A[i] < A[i - 1]) {
            int key = A[i];
            int j = i - 1;
            for (; key < A[j]; j--) A[j + 1] = A[j];
            A[j + 1] = key;
        }
    }
}

// 二分插入排序
void biInsertsort(int A[], int size) {
    for (int i = 1; i < size; i++) {
        int low = 0, high = i - 1;
        int key = A[i];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[i] < A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j > high; j--)
            A[j + 1] = A[j];
        A[high + 1] = key;
    }
}





