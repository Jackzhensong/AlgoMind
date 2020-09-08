
int n, m;
int dp[N][N], a[N][N];
int dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int dfs(int x, int y)
{
    if(dp[x][y] != -1) 
        return dp[x][y];
    dp[x][y] = 1;
    for(int k = 0; k < 4; ++k){
       int tx = x + dx[k];
       int ty = y + dy[k];
       if(tx >= 1 && tx <= n && ty <= m && a[x][y] > a[tx][ty])
            dp[x][y] = max(dp]x][y], dfs(tx, ty) + 1);
    } 
    return dp[x][y];
}
