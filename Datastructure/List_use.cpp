
/// 顺序表 ///

//typedef struct Lnode  *list;
typedef struct Lnode
{
    int array[MAXN];
    int last;
} LNode, *list;

list Ptrl;

list Makeempty()
{
    list Ptrl;
    Ptrl = (list)malloc(sizeof(struct Lnode));
    Ptrl->last = -1;
    return Ptrl;
}

int Find(int des, list Ptrl)
{
    int i = 0;
    while (i <= Ptrl->last && Ptrl->array[i] != des)
        i++;
    if (i > Ptrl->last)
        cout << -1 << endl;
    else
        return i;
}

void insert(int X, int i, list Ptrl)
{
    if (Ptrl->last == MAXN)
    {
        cout << "list is full" << endl;
        return;
    }
    if (i < 1 || i > Ptrl->last + 2)
    {
        cout << "error" << endl;
        return;
    }

    for (int j = Ptrl->last; j >= i - 1; --j)
    {
        Ptrl->array[j + 1] = Ptrl->array[j];
    }
    Ptrl->array[i - 1] = X;
    Ptrl->last++;
}


void Delete(int i, list Ptrl)
{
    if (i < 1 || i > Ptrl->last + 1)
    {
        cout << "element don't exit" << endl;
        return;
    }
    for (int j = i - 1; j < Ptrl->last; ++j)
    {
        Ptrl->array[j] = Ptrl->array[j + 1];
    }
    Ptrl->last--;
}