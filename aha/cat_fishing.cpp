#include<iostream>
#include<queue>
#include<stack>
using namespace std;

const int maxn = 1e3;

struct Queue {
    int data[maxn];
    int head;
    int rear;
};
struct Stack {
    int data[maxn];
    int top;
};

int main() {
    struct Queue q1, q2;
    struct Stack s;
    int book[10];
    int t;

    q1.head = 1; q1.rear = 1;
    q2.head = 1; q2.rear = 1;
    s.top = 0;

    for(int i = 1; i <= 9; ++i)
        book[i] = 0;
    for(int i = 0; i < 6; ++i) {
        cin >> q1.data[q1.rear];
        q1.rear++;
    }
    for(int i = 0; i < 6; ++i) {
        cin >> q2.data[q2.rear];
        q2.rear++;
    }

while(q1.head < q1.rear && q2.head < q2.rear) {
    t = q1.data[q1.head];
    if(book[t] == 0) {
        q1.head++;
        s.top++;
        s.data[s.top] = t;
        book[t] = 1;
    }
    else {
        q1.head++;
        q1.data[q1.rear] = t;
        q1.rear++;
        while(s.data[s.top] != t) {
            book[s.data[s.top]] = 0;
            q1.data[q1.rear] = s.data[s.top];
            q1.rear++;
            s.top--;
        }
        book[s.data[s.top]] = 0;
        q1.data[q1.rear] = s.data[s.top];
        q1.rear++;
        s.top--;
    }
    if(q1.head == q1.rear) break;
    
    t = q2.data[q2.head];
    if(book[t] == 0) {
        q2.head++;
        s.top++;
        s.data[s.top] = t;
        book[t] = 1;    
    }
    else {
        q2.head++;
        q2.data[q2.rear] = t;
        q2.rear++;
        while(s.data[s.top] != t) {
            book[s.data[s.top]] = 0;
            q2.data[q2.rear] = s.data[s.top];
            q2.rear++;
            s.top--;
        }
        book[s.data[s.top]] = 0;
        q2.data[q2.rear] = s.data[s.top];
        q2.rear++;
        s.top--;
    }
}

if(q2.head == q2.rear) {
    cout << "xiaohengwin" << endl;
    for(int i = q1.head; i < q1.rear; ++i)
        cout << q1.data[i] << " ";
    cout << endl;
    if(s.top > 0) {
        for(int i = 1; i <= s.top; ++i) 
            cout << s.data[i] << " ";
    }
    else cout << "No brand";
}

else {
    cout << "xiaohawin" << endl;
    for(int i = q2.head; i < q2.rear; ++i) 
        cout << q2.data[i] << " ";
    cout << endl;
    if(s.top > 0) {
        for(int i = 1; i <= s.top; ++i)
            cout << s.data[i] << " ";
    }
    else cout << "No brand";
}
    return 0;
}