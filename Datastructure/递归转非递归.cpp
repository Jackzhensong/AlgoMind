
// 递归求和
void test(int &sum) {
    int x;
    scanf("%d", &x);
    if (x == 0) sum = 0;
    else {
        test(sum);
        sum += x;
    }
    printf(sum);
}

// 利用栈转非递归
void test(int &sum) {
    Stack S;
    int x;
    scanf("%d", &x);
    InitStack(S);
    while (x) {
        Push(S, x);
        scanf("%d", &x);
    }
    sum = 0;
    printf(sum);
    while (Pop(S, x)) {
        sum += x;
        printf(sum);
    }
}

// 递归实现字符串逆序存储
void invertstore(char *A) {
    char ch;
    int i = 0;
    scanf("%c", &ch);
    if (ch != ' ') { // 空格符表示输入结束
        invertstore(A);
        A[i++] = ch;
    }
    A[i] = '\0';
}

