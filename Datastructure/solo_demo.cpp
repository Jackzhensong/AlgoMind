
CMyString &CMyString::operator=(const CMyString &str)
{
    if (this == &str)
        return *this;
    delete[] m_pdata;
    m_pdata = NULL;
    m_pdata = new char[strlen(str.m_pdata) + 1];
    strcpy(m_pdata, str.m_pdata);
    return *this;
}

CMyString &CMyString::operator=(const CMyString &str)
{
    if (this != &str)
    {
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pdata;
        strTemp.m_pdata = m_pdata;
        m_pdata = pTemp;
    }
    return *this;
}

/*
int F(int n)
{
    if (n == 0)
        return 1;
    else
        return F(n - 1) * n;
}

int F(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return F(n - 1) + F(n - 2);
}
*/

const int maxn = 11;
int n, P[maxn], hashtable[maxn] = {false};

void PrintP(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; ++x)
    {
        if (hashtable[x] == false)
        {
            P[index] = x;
            hashtable[x] = true;
            PrintP(index + 1);
            hashtable[x] = false;
        }
    }
}

//// queen ///
int count = 0;
void generateP(int index)
{
    if (index == n + 1)
    {
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (abs(i - j) == abs(P[i] - P[j]))
                {
                    flag = false;
                }
            }
        }
        if (flag)
            count++;
        return;
    }

    for (int x = 1; x <= n; ++x)
    {
        if (hashtable[x] == false)
        {
            P[index] = x;
            hashtable[x] = true;
            generateP(index + 1);
            hashtable[x] = false;
        }
    }
}

/// backtrack ///
void generateP(int index)
{
    if (index == n + 1)
    {
        count++;
        return;
    }
    for (int x = 1; x <= n; ++x)
    {
        if (hashtable[x] == false)
        {
            bool flag = true;
            for (int pre = 1; pre < index; ++pre)
            {
                if (abs(index - pre) == abs(x - P[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                P[index] = x;
                hashtable[x] = true;
                generateP(index + 1);
                hashtable[x] = false;
            }
        }
    }
}

