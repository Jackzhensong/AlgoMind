#include<bits/stdc++.h>     //数组实现堆栈
using namespace std;

int isempty(){
    if(top==-1) return 1;
    else return 0;
}
int push(int data){
    if(top>=max) return 0;
    else {
        stack[++top]=data;
        return 1;
    }
}
void pop(){
    if(isempty()) return -1;
    else return stack[top--];
}

const int MAXN=10;
struct Stack{
    int arra[MAXN];
    int top;
};
typedef struct Stack *s_stack;

void Push(int value, s_stack p){
    if(p->top==MAXN-1) {
        cout<<"full"<<endl;
        return ;
    }
    else {
        p->arra[++(p->top)]=value;
        return ;
    }
}

int Pop(sp p){
    if(p->top==-1) {
        cout<<"empty"<<endl;
        return ;
    }
    else {
        return (p->arra[(p->top)--])
    }
}

const int MaxSize =100;
struct Dstack{
    int data[MaxSize];
    int top1;
    int top2;
};
typedef struct Dstack *pstl;
struct Dstack S;
S.top1=-1;
S.top2=MaxSize;

void Push(pstl sp, int item, int tag){
    if(sp->top2-sp->top2==1){
        cout<<"full"<<endl;
        return ;
    }
    if(tag==1) 
        sp->data[++(sp->top1)]=item;
    else 
        sp->data[--(sp->top2)]=item;
}

int Pop(pstl sp,int tag){
    if(tag==1){
        if(sp->top1==-1) {
            cout<<"empty"<<endl;
            return;
            }
        else return sp->data[(sp->top1)--];
    }
    else {
        if(sp->top2==MaxSize) {
            cout<<"empty"<<endl;
            return ;
            }
        else return sp->data[(sp->top2)++];
    }
}
