// 从表尾到表头逆向建立单链表

LinkList CreatList(LinkList head)
{
    Elemtype x;
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    scanf(&x); // 输入x
    while (x != EOF)
    { // EOF表示结束
        // LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        p->data = x;
        p->next = head->next;
        head->next = p;
        scanf(&x);
    }
    return head;
}