#include<bits/stdc++.h>
using namespace std;

const int maxn=101;
int D[maxn][maxn];
int n;
int maxsum(int i, int j)
{
    if (i == n)
        return D[i][j];
    int x = maxsum(i + 1, j);
    int y = maxsum(i + 1, j + 1);
    return max(x, y) + D[i][j];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> D[i][j];
    cout << maxsum(1, 1) << endl;
    return 0;
}

//方法二
int sum[maxn][maxn];
int maxsum(int i, int j){
    if(sum[i][j]!=-1) return sum[i][j];
    if(i==n) sum[i][j]=D[i][j];
    else{
        int x=maxsum(i+1,j);
        int y=maxsum(i+1,j+1);
        sum[i][j]=D[i][j]+max(x,y);
    }
    return sum[i][j];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        cin>>D[i][j];
        sum[i][j]=-1;
    cout<<maxsum(1,1)<<endl;
    return 0;
}

//方法三：递归转递推
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        cin>>D[i][j];
    for(int i=1;i<=n;i++)
        sum[n][i]=D[n][i];
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
        sum[i][j]=max(sum[i+1][j],sum[i+1][j+1])+D[i][j];
    cout<<sum[1][1];
    return 0;
}

//方法四，空间优化
int *sum;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> D[i][j];
    sum = D[n]; //sum指向第n行
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            sum[j] = max(sum[j], sum[j + 1]) + D[i][j]; //将求得值放到底N行
    cout << sum[1] << endl;
    return 0;
}