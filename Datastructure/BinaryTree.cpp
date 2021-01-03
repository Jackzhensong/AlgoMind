#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

typedef struct node {
    char data;
    struct node *lchild, *rchild;
} bitree;

bitree * creat_tree() 
{
    bitree *t;
    char ch;
    cin >> ch;
    if(ch == '@')
        t = NULL;
    else {
        t = new(bitree);
        t->data = ch;
        t->lchild = creat_tree();
        t->rchild = creat_tree();
    }
    return (t);
}

void preorder(bitree *t) {
    if(t) {
        cout << t->data;
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(bitree * t) {
    if(t) {
        inorder(t->lchild);
        cout << t->data;
        inorder(t->rchild);
    }
}

void postorder(bitree *t) {
    if(t) {
        postorder(t->lchild);
        postorder(t->rchild);
        cout << t->data;
    }
}

int main() 
{
    bitree *tree;
    tree = creat_tree();

    preorder(tree);
    cout << endl;

    inorder(tree);
    cout << endl;

    postorder(tree);
    cout << endl;

    return 0;
}