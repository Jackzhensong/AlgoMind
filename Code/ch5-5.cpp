#include<bits/stdc++.h> //图像模糊处理
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) {
        cin>>a[i][j]; 
        b[i][j]=a[i][j];
        }
    for(int i=1;i<n-1;++i)
        for(int j=1;j<m-1;++j) {
            int s=(b[i][j]+b[i-1][j]+b[i+1][j]+b[i][j-1]+b[i][j+1]);
            int d=s/5;
            double f=(double)s/5;
            if(f-d-0.5>1e-6)
            ++d;
            a[i][j]=d;
        }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}