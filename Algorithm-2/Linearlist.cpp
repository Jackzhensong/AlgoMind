
typedef struct LNode * List;
struct LNode{
    int data[maxn];
    int last;
};
struct LNode L;
List p;

List makeempty(){
    List p;
    p = (List)malloc(sizeof(struct LNode));
    p -> last = -1;
    return p;
}

int Find(int x, List p){
    int i = 0;
    while(i <= p -> last && p -> data[i] != x)
        i++;
    if(i > p -> last) return -1;
    else return i;
}

void insert(int x, int i, List p){
    if(p -> last == maxn - 1)   return;
    if(i < 1 || i > p -> last + 2)  return;    //这里的i和数组的i不同

    for(int j = p -> last; j >= i - 1; --j)
        p -> data[j + 1] = p -> data[j];
    p -> data[i - 1] = x;
    p -> last++;
    return;
}

void deletex(int i, List p){
    if(i < 1 || i > p -> last + 1)  return;
    for(int j = i; j <= p -> last; ++j) 
        p -> data[j -1] = p -> data[j];
    p -> last--;
    return;
}