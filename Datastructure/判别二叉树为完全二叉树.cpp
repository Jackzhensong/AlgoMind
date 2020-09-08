
int judgecomplete(Bitree bt)
{
    int tag = 0;
    Bitree p = bt;
    Queue q;
    if (p == NULL)
        return 0;
    Enqueue(q, p);
    while (!QueueEmpty(q))
    {
        p = Dequeue(q);
        if (p->lchild && !tag)
            Enqueue(q, p->lchild);
        else if (p->lchild)
            return 0;
        else
            tag = 1;
            
        if (p->rchild && !tag)
            Enqueue(q, p->rchild);
        else if (p->rchild)
            return 0;
        else
            tag = 1;
    }
    return 1;
}