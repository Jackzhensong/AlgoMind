

/* 将一个数的各位逆置 */
long long Converse_Num(long long n) {
    int k = 1;
    while (n != 0) {
        if (n % 10 != 0 && k == 1) {
            cout << n % 10;
            k++;
        }
        else if (k != 1)
            cout << abs(n % 10);
        n /= 10;
    }
}

    