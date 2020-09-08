#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100;
int a[maxn][maxn];

int main(){
    int n, n1, n2;
    cin>>n>>n1>>n2;
    int kase = 0;
    int b[] = {0, -1, 1, 1, -1, 0, -1, 1, -1, 0, -1, 1, 0, 1, 0};

    for(int i = 0; i <= 4; ++i){
        for(int j = i; j <= 4; ++j){
            a[i][j] = b[kase++];
            a[j][i] = -a[i][j];
        }
    }
    
    int s1[n1], s2[n2];
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n1; ++i)
        cin>>s1[i];
    for(int i = 0; i < n2; ++i)
        cin>>s2[i];
    for(int i = 0; i < n; ++i){
        if(a[s1[i % n1]][s2[i % n2]] == 1)  ans1++;
        else if(a[s1[i % n1]][s2[i % n2]] == -1)  ans2++;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}