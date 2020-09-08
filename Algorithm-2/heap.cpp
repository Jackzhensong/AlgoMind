#include <iostream>
using namespace std;

typedef struct heapstruct *MaxHeap;
struct heapstruct
{
    int *elem;
    int size;
    int capacity;
};

MaxHeap CreatHeap(int maxsize) //创建堆
{
    //MaxHeap hp=(MaxHeap)malloc(sizeof(struct heapstruct));
    MaxHeap hp = new struct heapstruct();
    hp->elem = (int *)malloc(sizeof(int) * maxsize);
    hp->size = 0;
    hp->capacity = maxsize;
    hp->elem[0] = Maxdata;
    return hp;
}

void Insert(MaxHeap h, int item)
{
    if (isfull(h))
        return;
    int i = ++h->size;
    for (; h->elem[i / 2] < item; i /= 2)
    {
        h->elem[i] = h->elem[i / 2];
    }
    h->elem[i] = item;
}
