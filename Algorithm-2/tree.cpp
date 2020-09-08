#include<iostream>
using namespace std;

int ListSearch(int *tab, int k)     //线性查找
{
    int i;
    tab->data[0]=k;
    for(i = tab->length; tab->data[il != k; --i) ;
    return i;
}

int BinarySearch(int k, int *p)
{
    int left,right,mid;
    int left = 1;
    int right = p->length;
    while(left<=right){
        mid = (left+right)/2;
        if(p->data[mid] == k) return mid;
        else if(p->data[mid] < k)
            left = mid+1;
        else if(p->data[mid] > k)
            right = mid -1; 
    }
    return -1;
}

typedef struct TreeNode *BinTree;
struct TreeNode{
    int data;
    BinTree left;
    BinTree right;
};

//先序，中序，后序遍历递归算法
void ProOrdertraversal(BinTree BT){
    if(BT) {
        cout<<BT->data;
        ProOrdertraversal(BT->left);
        ProOrdertraversal(BT->right);
    }
}

void InOrdertraversal(BinTree BT){
    if(BT) {
        InOrdertraversal(BT->left);
        cout<<BT->data<<endl;
        InOrdertraversal(BT->right);
    }
}

void PostOrdertraversal(BinTree BT){
    if(BT) {
        PostOrdertraversal(BT->left);
        PostOrdertraversal(BT->right);
        cout<<BT->data<<endl;
    }
}

//非递归算法
void InOdertraversal(BinTree BT){
    BinTree T=BT;
    stack s=stackcreat(maxsize);
    while(T || !isEmpty()){
        while(T){
            Push(s,T);
            T=T->left;
        }
        if(!isEmpty()) {
            T=Pop(s);
            cout<<T->data;
            T=T->right;
        }
    }
}

void PreOrdertraversal(BinTree BT){
    BinTree T=BT;
    stack s=stackcreat(maxsize);
    while(T || !isEmpty()){
        while(T){
            cout<<T->data<<endl;
            Push(s,T);
            T=T->left;
        }
        if(!isEmpty()){
            T=Pop(s);
            T=T->right;
        }
    }
}


void PostOrdertraversal(BinTree BT){
    BinTree T=BT;
    stack s=stackcreat(maxsize);
    while(T || !isEmpty()){
        while(T){
            Push(s,T);
            T=T->left;
        }
        if(!isEmpty()){
            T=Pop(s);
            T=T->right;
            cout<<T->data<<endl;
        }
    }
}

void levelOrdertraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if(!BT) return ;
    Q=QueueCreat(Maxsize);
    AddQ(Q,BT);
    while(!isEmptyQ()){
        T=DeleteQ(Q);
        cout<<T->data;
        if(T->left) AddQ(T->left);
        if(T->right) AddQ(T->right);
    }
}

//求二叉树的高度
int PostOrderGethigh(BinTree BT)
{
    int lefthigh,righthigh,treehigh;
    if(BT){
        lefthigh= PostOrderGethigh(BT->left);
        righthigh = PostOrderGethigh(BT->right);
        treehigh = (lefthigh>righthigh)? lefthigh:righthigh;
        return treehigh+1;
    }
    else return 0;
}