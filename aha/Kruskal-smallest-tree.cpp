#include<iostream>
#include<algorithm>
using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

struct edge e[10];
int f[10] = {0};
int sum = 0, num = 0;
int n, m;

void quicksort(int left, int right) {
    //struct edge t;
    if(left > right) return;
    int i = left;
    int j = right;
    while(i != j) {
        while(e[j].w >= e[left].w && i < j) 
            j--;
        while(e[i].w <= e[left].w && i < j) 
            i++;
        if(i < j) 
            swap(e[i], e[j]);
    }
    swap(e[left], e[i]);

    quicksort(left, i - 1);
    quicksort(i + 1, right);
    return ;
}

int getf(int v) {
    if(f[v] == v) return v;
    else {
        f[v] = getf(f[v]);
        return f[v];
    }
}
int merge(int v, int u) {
    int t1 = getf(v);
    int t2 = getf(u);
    if(t1 != t2) {
        f[t2] = t1;
        return 1;
    }
    return 0;
} 

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) 
        cin >> e[i].u >> e[i].v >> e[i].w;
    quicksort(1, m);
    for(int i = 1; i <= n; ++i) 
        f[i] = i;
    
    // Kruskal
    for(int i = 1; i <= m; ++i) {
        if(merge(e[i].u, e[i].v)) {
            num++;
            sum += e[i].w;
        }
        if(num == n - 1) break;
    }

    cout << sum << endl;
    return 0;
}