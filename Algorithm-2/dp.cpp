

// 递归
int solve(int i, int j) {
    return a[i][j] + (i == n ? 0 : max(solve(i+1， j), solve(i+1, j+1)));
}

// 递推
for(int j = 1; j <= n; ++j)     
    d[n][j] = a[n][j];
for(int i = n-1; i >= 1; --i)
    for(int j = 1; j <= i; ++j) 
        d[i][j] = a[i][j] + max(d[i+1][j], d[i+1][j+1]);


// 记忆化搜索
memset(d, -1, sizeof(d));

int solve(int i, int j) {
    if(d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + (i == n ? 0 : max(solve(i+1, j), solve(i+1, j+1)));   
}