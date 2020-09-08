#include<iostream>
using namespace std;

const int maxn = 1e9;
int dis[10], book[10] = {0};
int h[10], pos[10], size;

void swap2(int x, int y) {
    int t = h[x];
    h[x] = h[y];
    h[y] = t;

    t = pos[h[x]];
    pos[h[x]] = pos[h[y]];
    pos[h[y]] = t;
    return;
}

void siftdown(int i) {
    int t, flag = 0;
    while(i * 2 <= size && flag == 0) {
        if(dis[h[i]] > dis[h[i * 2]]) 
            t = i * 2;
        else t = i;
        if(i * 2 + 1 <= size) {
            if(dis[h[t]] > dis[h[i * 2 + 1]]) 
                t = i * 2 + 1;
        }
        if(t != i) {
            swap2(t, i);
            i = t;
        }
        else flag = 1;
    }
    return ;
}

void siftup(int i) {
    int flag = 0;
    if(i == 1) return ;
    while(i != 1 && flag == 0) {
        if(dis[h[i]] < dis[h[i/2]]) 
            swap2(i, i/2);
        else flag = 1;
        i /= 2;
    }
    return ;
}

int pop() {
    int t = h[1];
    pos[t] = 0;
    h[1] = h[size];
    pos[h[1]] = 1;
    size--;
    siftdown(1);
    return t;
}

int main() {
    int n, m;
    int u[20], v[20], w[20], first[10], next[20];
    int num = 0, sum = 0;
    
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)     
        cin >> u[i] >> v[i] >> w[i];
    for(int i = m + 1; i <= 2 * m; ++i) {
        u[i] = v[i - m];
        v[i] = u[i - m];
        w[i] = w[i - m];
    }

    for(int i = 1; i <= n; ++i) first[i] = -1;
    for(int i = 1; i <= 2 * m; ++i) {
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    book[1] = 1;
    num++;
    for(int i = 1; i <= n; ++i) 
        dis[i] = maxn;
    dis[1] = 0;

    int k = first[1];
    while(k != -1) {
        dis[v[k]] = w[k];
        k = next[k];
    }

    size = n;
    for(int i = 1; i <= size; ++i) {
        h[i] = i;
        pos[i] = i;
    }
    for(int i = size / 2; i >= 1; --i) siftdown(i);
    pop();

    while(num < n) {
        int j = pop();
        book[j] = 1;
        num++;
        sum += dis[j];

        k = first[j];
        while(k != -1) {
            if(book[v[k]] == 0 && dis[v[k]] > w[k]) {
                dis[v[k]] = w[k];
                siftup(pos[v[k]]);
            }
            k = next[k];
        }
    }

    cout << sum << endl;
    return 0;
}