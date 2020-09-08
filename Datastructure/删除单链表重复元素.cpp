// 删除单链表中的重复元素

LinkList Delect(LinkList head) {
    pre = head->next;
    while(pre != NULL) {
        m = pre->data;
        q = pre;
        p = pre->next;
        while(p != NULL) {
            if(p->data == m) {
                u = p;
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