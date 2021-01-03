

const int maxn = 11;
int P[maxn];
bool hashtable[maxn] = {false};
int n;

// 输出所有排列 1 ~ n
void PrintP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; ++i) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; ++x) {
        if (hashtable[x] == false) {
            P[index] = x;
            hashtable[x] = true;
            PrintP(index + 1);
            hashtable[x] = false;
        }
    }
}


/// queen -- 八王后系列问题
int count1 = 0;

void generateP(int index) {
    if (index == n + 1) {
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (abs(i - j) == abs(P[i] - P[j])) {
                    flag = false;
                }
            }
        }
        if (flag) count1++;
        return;
    }
    for (int x = 1; x <= n; ++x) {
        if (hashtable[x] == false) {
            P[index] = x;
            hashtable[x] = true;
            generateP(index + 1);
            hashtable[x] = false;
        }
    }
}


/// backtrack -- 回溯法
void generateP(int index) {
    if (index == n + 1) {
        count1++;
        return;
    }
    for (int x = 1; x <= n; ++x) {
        if (hashtable[x] == false) {
            bool flag = true;
            for (int pre = 1; pre < index; ++pre) {
                if (abs(index - pre) == abs(x - P[pre])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                P[index] = x;
                hashtable[x] = true;
                generateP(index + 1);
                hashtable[x] = false;
            }
        }
    }
}


