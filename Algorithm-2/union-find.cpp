#include<bits/stdc++.h>
using namespace std;

int pre[1010];  //存放第 i 个元素的父节点
int unionsearch(int root) {  // 查找根节点
    int son, tmp;
    son = root;
    while(root != pre[root])  // 寻找根节点
        root = pre[root]; 

    while(son != root) {   // 路径压缩
        tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }
    return root;
}
/*
void join(int root1, int root2) { // 判断是否连通，不连通就合并
    int x, y;
    x = unionsearch(root1);
    y = unionsearch(root2);
    if(x != y) pre[x] = y;
}
*/
int main() {
    int num, road, total, start, end;
    while(cin >> num && num && cin >> road) {
        total = num - 1;
        for(int i = 1; i <= num; ++i) 
            pre[i] = i;
        while(road--) {
            cin >> start >> end;
            int root1 = unionsearch(start);
            int root2 = unionsearch(end);
            if(root1 != root2) {
                pre[root1] = root2;
                total--;
            }
        }
        cout << total << endl;
    }
    return 0;
}