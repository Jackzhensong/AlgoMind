#include<bits/stdc++.h>
using namespace std;

 /*
const int maxn = 10;
void printN(int n){
    if(n != 0) {
        printN(n - 1);
        cout<< n << endl;
    }
    return ;
}
int main() {
    int  n;
    cin >> n;
    printN(n);
    return 0;
}
*/

/*
template <typename T>
void print(const T array[], T size)
{
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    return;
}

int main()
{
    int a[5];
    for (int i = 0; i < 5; ++i)
        cin >> a[i];
    print(a, 5);
    return 0;
}
 */
typedef struct BiTNode{
	char data;
	BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
 
void CreateBiTree(BiTree &T)//建树
{
	char ch;
	scanf("%c",&ch);
	if(ch == ' ')
	{
		T = NULL;
		//abd return;
	}
	else
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(1);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void LevelOrderTraverse(BiTree T)//层次遍历
{
	queue<BiTree> Queue;
	if(!T)
	{
		printf("空树！\n");
		return;
	}
	Queue.push(T);
	while(!Queue.empty())
	{
		T=Queue.front();
		Queue.pop();
		printf("%c",T->data);
		if(T->lchild)
			Queue.push(T->lchild);
		if(T->rchild)
	        Queue.push(T->rchild);	    
	}
}
int main()
{
  
	BiTree T;
	CreateBiTree(T);
	LevelOrderTraverse(T);
	printf("\n");
    return 0;
}



/*
int main() {
    //int n;
    //cin >> n;
    //int a[n];
    //for (int i = 0; i < n; ++i) cin >> a[i];
    
    //for (int i = 0; i < n; ++i) cout << a[i] << " ";
    int n;
    cin >> n;
    cout << fib(n);
    //for (int i = 0; i < n; ++i) cout << fib(i) << endl;
    return 0;
}
*/