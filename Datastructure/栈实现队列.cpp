// 用两个栈实现队列

// 入队
bool Enqueue(Stack S1, Elemtype e) {
    if(top1 == n && !Sempty(S2)) {
        printf("栈满");
        return false;
    }
    if(top1 == n && Sempty(S2)) {
        while(!Sempty(S1)) {
            Pop(S1, e);
            Push(S2, e);
        }
    }
    Push(S1, e);
    return true;
}

// 出队
void Dequeue(Stack S1, Stack S2) {
    if(!Sempty(S2)) {
        Pop(S2, e);
        printf("出队元素为", e);
    }
    else {
        if(Sempty(S1)) {
            printf("队列空");
            return false;
        }
        else {
            while(!Sempty(S1)) {
                Pop(S1, e);
                Push(S2, e);
            }
            Pop(S2, e);
            printf("出队元素", e);
        }
    }
}

// 判空
bool Queue_empty() {
    if(Sempty(S1) && Sempty(S2))
        return true;
    else 
        return false;
}