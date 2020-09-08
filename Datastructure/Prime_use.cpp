

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    int cnt = (int)sqrt(n * 1.0);
    for (int i = 2; i <= cnt; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

const int maxn = 101;
int prime[maxn], num = 0;
bool p[maxn] = {0};
void find_prime()
{
    for (int i = 2; i < maxn; ++i)
    {
        if (!p[i])
        {
            prime[num++] = i;
            for (int j = i * 2; j < maxn; j += i)
            {
                p[j] = true;
            }
        }
    }
}

/// prime faction decompsition
const int maxn = 1e4 + 10;
int prime[num], num = 0;
bool p[maxn] = {0};
void find_prime()
{
    for (int i = 2; i < maxn; ++i)
    {
        if (!p[i])
        {
            prime[num++] = i;
            for (int j = 2 * i; j < maxn; j += i)
                p[j] = true;
        }
    }
}

int main()
{
    find_prime();
    int n, num = 0;
    cin >> n;
    if (n == 1)
        cout << "1=1";
    else
    {
        cout << "n=" << n;
        int sqr = (int)sqrt(n * 1.0);
        for (int i = 0; i < pnum && prime[i] <= sqr; ++i)
        {
            if (n % prime[i] == 0)
            {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0)
                {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1)
                break;
        }
        if (n != 1)
        {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }

        for (int i = 0; i < num; ++i)
        {
            if (i > 0)
                cout << "*";
            cout << fac[i].x;
            if (fac[i].cnt > 1)
                cout << "^" << fac[i].cnt;
        }
    }
    return 0;
}
