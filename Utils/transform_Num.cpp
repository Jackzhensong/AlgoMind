
// 无符号数十进制数num输出其对应的r进制的各位数字
typedef struct node {
    int data;
    struct node *next;
} link;

void trans(int num, int r) {
    link *head = NULL;
    link *s;
    int n;
    while (num > 0) {
        n = num % r;
        s = (link *)malloc(sizeof(link));
        s->data = n;            // 逆序建链表
        s->next = head;
        head = s;
        num /= r;
    }
    s = head;
    while (s != NULL) {
        printf("%d", s->data);
        s = s->next;
    }
}

