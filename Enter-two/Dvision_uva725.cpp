#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
 
int use[10];
bool  judge(int x, int y){
    memset(use, 0, sizeof(use));
    if(x > 98765) return false;
    if(y < 10000)  use[0] = 1;
    while(x || y){
        int id = x % 10;
        x /= 10;
        use[id] = 1;
        id = y % 10;
        y /= 10;
        use[id] = 1;
    }
    int sum = 0;
    for(int i = 0; i < 10; ++i)
        if(use[i]) sum++;
    if(sum == 10) return true;
    return false;
}

int main(){
    int n;
    int kase = 0;
    while(scanf("%d", &n) == 1){
        if(kase++) cout<<endl;
        bool ans = true;
        for(int i = 1234; i < 98765; ++i){
            if(judge(n * i, i)){
                ans = false;
                printf("%05d / %05d = %d\n", i * n, i, n);
            }
        }
        if(ans)
            cout<<"No"<<endl;
    }
    return 0;
}