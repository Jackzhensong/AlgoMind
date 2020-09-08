#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[30];
int n;
int ways(int w, int k){
    if(w == 0) return 1;
    if(k <= 0) return 0;
    return ways(w, k - 1) + ways(w - a[k], k - 1);
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    cout<<ways(40, n)<<endl;
    return 0;
}


int a[30];
int n;
int ways[50][40];

int main(){
    cin>>n;
    memset(ways, 0, sizeof(ways));
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        ways[0][i] = 1;
    }
    ways[0][0] = 1;
    for(int w = 1; w <= 40; ++w)
        for(int k = 1; k <= n; ++k){
            ways[w][k] = ways[w][k - 1];
            if(w - a[k] >= 0) 
                ways[w][k] += ways[w - a[k]][k - 1];
        }
    cout<<ways[40][n]<<endl;
    return 0;
}