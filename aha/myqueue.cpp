#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 100;

int main() {
    int n;
    int q[maxn];
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        cin >> q[i];
    int head = 1;
    int rear = n + 1;
    while(head < rear) {
        cout << q[head] << " ";
        head++;
        q[rear] = q[head];
        rear++;
        head++;
    }
    return 0;
}

// struct queue
struct queue {
    int data[maxn];
    int head;
    int rear;
};

int main() {
    struct queue q;
    int n;
    cin >> n;
    q.head = 1;
    q.rear = 1;
    for(int i = 0; i < n; ++i) {
        cin >> q.data[q.rear];
        q.rear++;
    }
    while(q.head < q.rear) {
        cout << q.data[q.head];
        q.head++;
        q.data[q.rear] = q.data[q.head];
        q.rear++;
        q.head++;
    }
    return 0;
}

// STL queue
int main() {
    int n, data;
    cin >> n;
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        cin >> data;
        q.push(data);
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}