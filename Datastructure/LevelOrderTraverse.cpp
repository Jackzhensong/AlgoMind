#include<bits/stdc++.h>
using namespace std;


typedef struct BiTNode {
	char data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


//建树
void CreateBiTree(BiTree &T) {
	char ch;
	scanf("%c", &ch);
	if (ch == ' ') {
		T = NULL;
		return;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) exit(1);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}


//层次遍历
void LevelOrderTraverse(BiTree T) {
	queue<BiTree> Queue;
	if (!T) {
		printf("空树！\n");
		return;
	}
	Queue.push(T);
	while (!Queue.empty()) {
		T = Queue.front();
		Queue.pop();
		printf("%c", T->data);
		if (T->lchild)	Queue.push(T->lchild);
		if (T->rchild)	Queue.push(T->rchild);
	}
}


int main() {
	BiTree T;
	CreateBiTree(T);
	LevelOrderTraverse(T);
	printf("\n");
	return 0;
}