
tot = 0;
best = A[1];
for(int i = 1; i <= n; ++)
    for(int j = i;  j <= n; ++j) {
        int sum = 0;
        for(int k = i; k <= j; ++k) {    // 检查连续子序列 A[i], .... , A[j]
            sum += A[k];
            tot++;
        }
        if(sum > best) best = sum;
    }


S[0] = 0;
for(int i = 1; i <= n; ++i) 
    S[i] = S[i-1] + A[i];       
for(int i = 1; i <= n; ++i) 
    for(int j = i; j <= n; ++j) 
        best = max(best, S[j] - S[i-1]);


int maxsum(int* A, int x, int y) {
    int v, L, R, maxs;
    if(y - x == 1) return A[x];
    int m = x + (y - x) / 2;
    maxs = max(maxsum(A, x, m), maxsum(A, m, y));
    v = 0;
    L = A[m-1];
    for(int i = m-1; i >= x; --i) L= max(L, v += A[i]);

    v = 0; 
    R = A[m];
    for(int i = m; i < y; ++i) R = max(R, v += A[i]);
    return max(maxs, L + R); 
}