
 //希尔排序，不稳定排序
void shell(int a[], int size) {
    int k = size / 2;
    while (k != 0) {
        for (int i = k; i < size; ++i) {
            int tmp = a[i];
            int j = i - k;
            while (tmp < a[j] && j >= 0) {
                a[j + k] = a[j];
                j -= k;
            }
            a[j + k] = tmp;
        }
        k /= 2;
    }
}






