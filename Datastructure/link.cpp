
/// 单链表 ///
typedef struct Node {
    int data;
    struct Node *next;
} LinkNode, *link;


int length(link ptrl) {
    link p = ptrl;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

link Findth(int i, link ptrl) {
    link p = ptrl;
    int j = 1;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (i == j)
        return p;
    else
        return NULL;
}

link Find(int data, link ptrl) {
    link p = ptrl;
    while (p->data != data && p != NULL)
        p = p->next;
    return p;
}

link insert(int X, int i, link ptrl) {
    link p, s;
    if (i == 1) {
        s = (link)malloc(sizeof(struct Link));
        s->data = X;
        s->next = ptrl;
        return s;
    }
    p = Findth(i - 1, ptrl);
    if (p == NULL) {
        cout << "error" << endl;
        return NULL;
    }
    else {
        s = (Link)malloc(sizeof(struct Link));
        s->data = X;
        s->next = p->next;
        p->next = s;
        return ptrl;
    }
}

// 删除单链表中的重复元素
link Delect(link head) {
    link pre = head->next;
    while(pre != NULL) {
        int m = pre->data;
        link q = pre;
        link p = pre->next;
        while(p != NULL) {
            if(p->data == m) {
                link u = p;
                p = p->next;
                free(u);
            }
            else {
                q->next = p;
                q = p;
                p = p->next;
            }
        }
        q->next = p;
        pre = pre->next;
    }
    return head;
}

// 从表尾到表头逆向建立单链表
link CreatList(link head) {
    Elemtype x;
    head = (link)malloc(sizeof(LinkNode));
    head->next = NULL;
    scanf(&x);               // 输入x
    link p;
    while (x != EOF) {      // EOF表示结束
        p = (link)malloc(sizeof(LinkNode));
        p->data = x;
        p->next = head->next;
        head->next = p;
        scanf(&x);
    }
    return head;
}