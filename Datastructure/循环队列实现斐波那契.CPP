
// 循环队列实现斐波那契数列
void getfib(int k, int n)
{
    InitQueue(Q);
    for (int i = 0; i < k - 1; i++)
        Q.base[i] = 0;
    Q.base[k - 1] = 1;
    for (i = 0; i < k; i++)
        printf("%d", Q.base[i]);
    for (i = k; i <= n; i++)
    {
        m = i % k;
        sum = 0;
        for (j = 0; j < k; j++)
            sum += Q.base[(m + j) % k];
        Q.base[m] = sum;
        printf("%d", sum);
    }
}