#include<bits/stdc++.h>
using namespace std;

typedef int State[9];            // 定义“状态”类型
const int maxstate = 1e6;
State st[maxstate], goal;       //状态数组，所有状态都保存在这里
int dist[maxstate];             //距离数组

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int bfs() {
    init_lookup_table();            // 初始化查找表
    int front = 1, rear = 2;        //不使用下标0， 0 看作“不存在”
    while(front < rear) {
        State & s = st[front];          // 用“引用” 简化代码
        if(memcmp(goal, s, sizeof(s)) == 0) 
            return front;               // 找到目标状态，成功返回
        int z;
        for(z = 0; z < 9; ++z) 
            if(!s[z]) break;            // 找0 的位置
        int x = z/3, y = z%3;           // 获取行列编号(0 ~ 2)
        for(int d = 0; d < 4; ++d) {
            int newx = x + dx[d];
            int newy = y + dy[d];
            int newz = newx * 3 + newy;
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {      // 如果移动合法
                State &t = st[rear];
                memcmp(&t, &s, sizeof(s));              // 扩展新结点
                t[newz] = s[z];
                t[z] = s[newz];
                dist[rear] = dist[front] + 1;           // 更新新结点的距离值
                if(try_to_insert(rear)) rear++;         // 如果成功插入查找表，修改队尾指针
            }
        }
        front++;            // 扩展完毕后再修改队首指针
    }
    return 0;               // 失败
}

int main() {
    for(int i = 0; i < 9; ++i) 
        cin >> st[1][i];
    for(int i = 0; i < 9; ++i) 
        cin >> goal[i];
    int ans = bfs();
    if(ans > 0)  cout << dist[ans];
    else cout << -1 << endl;
    return 0;
}



int vis[362880], fact[9];
void init_lookup_table() {
    fact[0] = 1;
    for(int i = 1; i < 9; ++i) 
        fact[i] = fact[i-1] * i;
}

int try_to_insert(int s) {
    int code = 0;
    for(int i = 0; i < 9; ++i) {
        int cnt = 0;
        for(int j = i + 1; j < 9; ++j) 
            if(st[s][j] < st[s][i]) cnt++;
        code += fact[8-i] * cnt;
    }
    if(vis[code]) return 0;
    return vis[code] = 1;
}


//hash
const int hashsize = 1e6;
int head[hashsize], next[maxstate];

void init_lookup_table() {
    memset(head, 0, sizeof(head));
}

in hash(State &s) {
    int v = 0;
    for(int i = 0; i < 9; ++i)
        v = v * 10 + s[i];          // 把九个数组合成9位数
    return v % hashisze;            // 确保hash函数值是不超过hash表的大小的非负整数
}

int try_to_insert(int s) {
    int h = hash(st[s]);
    int u = head[h];            // 从表头开始查找链表
    while(u) {
        if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;      // 找到了，插入失败
        u = next[u];            // 顺着链表继续找
    }
    next[s] = head[h];          // 插入到链表中
    head[h] = s;
    return 1;
}


// STL
set<int> vis;
void init_lookup_table() { vis.clear(); }

int try_to_insert(int s) {
    int v = 0;
    for(int i = 0; i < 9; ++i) 
        v = v * 10 + st[s][i];
    if(vis.count(v)) return 0;
    vis.insert(v);
    return 1;
}