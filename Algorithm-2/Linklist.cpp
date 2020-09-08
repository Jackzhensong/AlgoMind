
typedef struct LNode * Link;
struct LNode{
    int data;
    link next;
};

struct LNode L;
Link p;

int Length(Link p){
    Link pt = p;
    int j = 0;
    while(pt){
        pt = pt -> next;
        j++; 
    }
    return j;
}

Link FindKth(int k, Link p){
    Link pt = p;
    int i = 1;
    while(pt != NULL && i < k){
        pt = pt -> next;
        i++;
    }
    if(i == k) return pt;
    else return NULL;
}

Link Findvalue(int x, Link p){
    Link pt = p;
    while(pt != NULL && p -> data != x)
        pt = pt -> next;
    return pt;
}

Link insert(int x, int i, Link p){
    Link pt, ps;
    if(i == 1){
        ps = (Link)malloc(sizeof(struct LNode));
        ps -> data = x;
        ps -> next = p;
        return ps;
    }
    pt = FindKth(i - 1, p);
    if(pt == NULL) return NULL;
    else {
        ps = (Link)malloc(sizeof(struct LNod));
        ps -> data = x;
        ps -> next = pt ->next;
        pt -> next = ps;
        return p;
    }
}

link deletex(int i, Link p){
    Link pt, ps;
    if(i == 1){
        ps = p;
        p = p -> next;
        free(ps);
        return p;
    }
    pt = FindKth(i - 1, p);
    if(pt == NULL)      return NULL;
    else if(pt -> next == NULL)    return NULL;
    else {
        ps = pt -> next;
        pt -> next = ps ->next;
        free(ps);
        return p;
    }
}