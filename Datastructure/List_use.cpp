
/// 顺序表 ///
typedef struct Lnode {
    int array[MAXN];
    int size;
} LNode, *list;


list Makeempty() {
    list Ptrl;
    Ptrl = (list)malloc(sizeof(struct Lnode));
    Ptrl->size = -1;
    return Ptrl;
}

int Find(int des, list Ptrl) {
    int i = 0;
    while (i <= Ptrl->size && Ptrl->array[i] != des) i++;
    if (i > Ptrl->size)
        cout << -1 << endl;
    else
        return i;
}

void insert(int X, int i, list Ptrl) {
    if (Ptrl->size == MAXN) {
        cout << "list is full" << endl;
        return;
    }
    if (i < 1 || i > Ptrl->size + 2) {
        cout << "error" << endl;
        return;
    }

    for (int j = Ptrl->size; j >= i - 1; --j) {
        Ptrl->array[j + 1] = Ptrl->array[j];
    }
    Ptrl->array[i - 1] = X;
    Ptrl->size++;
}


void Delete(int i, list Ptrl) {
    if (i < 1 || i > Ptrl->size + 1) {
        cout << "element don't exit" << endl;
        return;
    }

    for (int j = i - 1; j < Ptrl->size; ++j) {
        Ptrl->array[j] = Ptrl->array[j + 1];
    }
    Ptrl->size--;
}