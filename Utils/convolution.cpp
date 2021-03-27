
// convolution 
void conv(int a[], int b[], int c[]) {
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            c[j + i] += a[i] * b[j];
    }
}
