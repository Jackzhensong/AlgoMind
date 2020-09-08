#include<cstdio>
#include<iostream>
using namespace std;

int n, L, cnt;
int S[100];

int dfs(int cur) {      // 返回零表示已经得到解， 无须继续搜索
    if(cnt++ == n) {
        for(int i = 0; i < cur; i++) {
            //if(i % 64 == 0 && i > 0) cout << endl;
            printf("%c", 'A' + S[i]);
        }  
        printf("\n");
        return 0;
    }
    for(int i = 0; i < L; ++i) {
        S[cur] = i;
        int ok = 1;
        for(int j = 1; j * 2 <= cur + 1; ++j) {     // 尝试长度为 j * 2 的后缀
            int equal = 1;
            for(int k = 0; k < j; ++k)              // 检查后一半是否等于前一半
                if(S[cur-k] != S[cur-k-j]) { equal = 0; break; }
            if(equal) { ok = 0; break; } 
        }
        if(ok) 
            if(!dfs(cur + 1)) return 0;
    }
    return 1;
}

int main() {
    while(cin >> n >> L && n > 0) {
        cnt = 0;
        dfs(0);
    }
    return 0;
}