
// 找有序数组中和为某个数的两个数
bool FindnumS(int *data, int length, int sum, int *num1, int* num2) {
    bool found = false;
    if(length < 1 || num1 == NULL || num2 == NULL) 
        return found;
    int behind = length - 1;
    int ahead = 0;

    while(ahead < behind) {
        long long cursum = data[ahead] + data[behind];
        if(cursum == sum) {
            *num1 = data[ahead];
            *num2 = data[behind];
            found = true;
            break;
        }
        else if(cursum > sum)   behind --;
        else ahead ++;
    }
    return found;
}


// 找和为sum的连续数列
void findseriesSum(int sum) {
    if(sum < 3) return;

    int small = 1;
    int big = 2;
    int mid = (1 + sum) / 2;
    int cursum = small + big;

    while(small < mid) {
        if(cursum == sum)  PrintSequence(small, big);
        while(cursum > sum && small < mid){
            cursum -= small;
            small ++;
            if(cursum == sum) PrintSequence(small, big);
        }
        big ++;
        cursum += big;
    }
}

void PrintSequence(int small, int big) {
    for(int i = small; i < big; ++i)
        printf("%d ", i);
        printf("\n");
}