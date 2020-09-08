#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int d = m / n; d >= 1; -- d){
        int ret = m / d;
        if(m % d == 0 && ret >= n){
            printf("%d\n", d);
            break;
        }
    }
    return 0;
}