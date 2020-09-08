#include <iostream>
using namespace std;
const int MAXN = 10;

/// 单链表 ///
typedef struct Link *link;
struct Link
{
    int data;
    link next;
};

int length(link ptrl)
{
    link p = ptrl;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

link Findth(int i, link ptrl)
{
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

link Find(int data, link ptrl)
{
    link p = ptrl;
    while (p->data != data && p != NULL)
        p = p->next;
    return p;
}

link insert(int X, int i, link ptrl)
{
    link p, s;
    if (i == 1)
    {
        s = (link)malloc(sizeof(struct Link));
        s->data = X;
        s->next = ptrl;
        return s;
    }
    p = Findth(i - 1, ptrl);
    if (p == NULL)
    {
        cout << "error" << endl;
        return NULL;
    }
    else
    {
        s = (Link)malloc(sizeof(struct Link));
        s->data = X;
        s->next = p->next;
        p->next = s;
        return ptrl;
    }
}