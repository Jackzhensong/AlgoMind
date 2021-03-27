
// 判断质数
bool isPrime(int n) {
    if (n <= 1) return false;
    int cnt = (int)sqrt(n * 1.0);
    for (int i = 2; i <= cnt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


// 找范围为: 2 ~ N 内的所有质数
const int maxn = 101;
int prime[maxn];
bool tag[maxn] = {0};

void find_prime(int N) {
    int num = 0;
    for (int i = 2; i < N; ++i) {
        if (!tag[i]) {
            prime[num++] = i;
            for (int j = i * 2; j < maxn; j += i) 
                tag[j] = true;
        }
    }
}
