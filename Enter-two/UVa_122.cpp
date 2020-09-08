#include<bits/stdc++.h>
using namespace std;

const int maxn = 256 + 10;
char s[maxn];

struct Node{
    bool havevalue;     //是否被赋值过
    int v;              //节点值
    Node *left, *right;
    Node():havevalue(false), left(NULL), right(NULL) { }
};

Node *root;
Node *newnode() {return new Node();}

void remove_tree(Node * u){
    if(u == NULL) return ;
    remove_tree(u -> left);
    remove_tree(u ->right);
    delete u;
}

bool readInput() {
    failed = false;
    remove_tree(root);
    root = newnode();   //创建根节点
    for(; ;){
        if((cin>>s) != 1) return false;    //整个输入结束
        if(!strcmp(s, "()")) break;      //读到结束标志，退出循环
        int v;
        sscanf(&s[1], "%d", &v);    //读入节点值
        addnode(v, strchr(s, ',') + 1);     //查找逗号， 然后插入节点
    }
    return true;
}

void addnode(int v, char *s){
    int n = strlen(s);
    Node *u = root;
    for(int i = 0; i < n; ++i)
        if(s[i] == 'L'){
            if(u ->left == NULL) u ->left = newnode(); //节点不存在，建立新节点
            u = u ->left;
        }
        else if(s[i] == 'R'){
            if(u ->right == NULL) u->right = newnode();
            u = u ->right;
        }
    if(u -> havevalue)  failed = true;
    u->v = v;
    u->havevalue = true;
}

bool bfs(vector<int> & ans){
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node * u = q.front();
        q.pop();
        if(!u -> havevalue) return false;   //有节点没有被赋值过，说明输入有误
        ans.push_back(u -> v);              //增加到输出序列尾部
        if(u -> left != NULL) q.push(u -> left);    //把左子节点放进队列
        if(u -> right != NULL) q.push(u ->right);   //把右子节点放进队列
    }
    return true;
}


