
#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#include <queue>
using namespace std;
// 顺序储存二叉树

// 链式储存二叉树
/*
typedef struct tNode {
    TElemtype data;
    struct tNode* lchild;
    struct tNode* rchild;
}BiTNode, *BiTree;

// 等价写法
struct tNode {
    TElemtype data;
    struct tNode* lchild;
    struct tNode* rchild;
};
typedef struct tNode  BiTNode;
typedef struct tNode* BiTree;

// 写法二
typedef struct tNode  BiTNode;
typedef struct tNode* BiTree;
struct tNode {
    TElemtype data;
    BiTNode* lchild;
    BiTNode* rchild;
};
*/

typedef int Status;
typedef int TElemtype;

typedef struct tNode
{
    TElemtype data;
    struct tNode *lchild, *rchild;
} BiTNode, *BiTree;

/*
BiTNode *newbitnode(int data)
{
    BiTNode *btnode = (BiTNode *)malloc(sizeof(BiTNode));
    btnode->data = data;
    btnode->lchild = NULL;
    btnode->rchild = NULL;
    return btnode;
}
*/
void Creatbitree(BiTree &T) {
    Status x;
    scanf("%d", &x);
    if (x == 0) {
        T = NULL;
        return;
    }
    else {
        T = (BiTree)malloc(sizeof(BiTNode));
        //if(!T) exit(1);
        T->data = x;
        Creatbitree(T->lchild);
        Creatbitree(T->rchild);
    }
}

void printBitree(BiTree T)
{
    if (T)
    {
        printf("%d\n", T->data);
    }
    if (T->lchild)
    {
        printf("%d, lchild: ", T->data);
        printBitree(T->lchild);
    }
    if (T->rchild)
    {
        printf("%d, rchild: ", T->data);
        printBitree(T->rchild);
    }
}

void DestoryBiTree(BiTree &T)
{
    if (T)
    {
        DestoryBiTree(T->lchild);
        DestoryBiTree(T->rchild);
        free(T);
    }
}

void visit(BiTree T)
{
    printf("%2d", T->data);
}

// 先序遍历
// Status preorder(BiTree T, Status(*visit)(TElemtype))
void preorder(BiTree T)
{
    if (T)
    {
        //visit(T);
        printf("%2d", T->data);
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
// 中序遍历
void inorder(BiTree T)
{
    if (T)
    {
        inorder(T->lchild);
        printf("%2d", T->data);
        inorder(T->rchild);
    }
}
// 后序遍历
void postorder(BiTree T)
{
    if (T)
    {
        postorder(T->lchild);
        postorder(T->rchild);
        printf("%2d", T->data);
    }
}
// 层次遍历
void levelorder(BiTree T)
{
    queue<BiTree> Queue;
    if (T)
    {
        Queue.push(T);
        while (!Queue.empty())
        {
            T = Queue.front();
            Queue.pop();
            visit(T);
            if (T->lchild)
                Queue.push(T->lchild);
            if (T->rchild)
                Queue.push(T->rchild);
        }
    }
}


int main()
{
    BiTree btroot;
    /*
    btroot = newbitnode(1);
    btroot->lchild = newbitnode(2);
    btroot->rchild = newbitnode(3);
    btroot->lchild->lchild = newbitnode(4);
    btroot->lchild->rchild = newbitnode(5);
    btroot->rchild->lchild = newbitnode(6);
    */

    Creatbitree(btroot);

    printf("\npreorder: ");
    preorder(btroot);
    printf("\ninorder: ");
    inorder(btroot);
    printf("\npostorder: ");
    postorder(btroot);
    printf("\nlevelorder: ");
    levelorder(btroot);
    //postorder(btroot, *visit);

    printf("\n");
    printBitree(btroot);
    DestoryBiTree(btroot);
    return 0;
}