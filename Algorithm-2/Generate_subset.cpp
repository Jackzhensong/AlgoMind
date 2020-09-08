#include<bits/stdc++.h>
using namespace std;

//增量构造法
void print_subset(int n, int* A, int cur) {
    for (int i = 0; i < cur; ++i) 
        printf("%d ", A[i]);
    printf("\n");
    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; ++i) {
        A[cur] = i;
        print_subset(m, A, cur + 1);
    }
}

// 位向量法
void print_subset(int n, int* B, int cur) {
    if(cur == n) {
        for(int i = 0; i < cur; ++i)
            if(B[i]) printf("%d ", i);
        printf("\n");
        return ;
    }
    B[cur] = 1;
    print_subset(n, B, cur + 1);
    B[cur] = 0;
    print_subset(n, B, cur + 1);
}

//二进制法

// 打印{0, 1, 2, ... , n-1} 的子集 s
void print_subset(int n, int s) {
    for(int i = 0; i < n; ++i) 
        if(s & (1 << i)) printf("%d ", i);
    printf("\n");
}

int main() {
    int n;
    cin >> n;
    //print_subset(10, s);
    for(int i = 0; i < (1 << n); ++i) {
        print_subset(n, i);
}

    return 0;
}

//枚举个子集所对应的编码
