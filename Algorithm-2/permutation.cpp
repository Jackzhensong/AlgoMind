#include <bits/stdc++.h>
using namespace std;

/// 生成排列数 ///
void print_permutation(int n, int *A, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", A[i]);
        printf("\n");
    }

    else
        for (int i = 1; i <= n; ++i)
        {
            int ok = 1;
            for (int j = 0; j < cur; ++j)
                if (A[j] == i)
                    ok = 0;
            if (ok)
            {
                A[cur] = i;
                print_permutation(n, A, cur + 1);
            }
        }
}

int main() {
    int n;
    cin >> n;
    int A[n + 5];
    print_permutation(n, A, 0);
    return 0;
}


/// other solution ///
else for(int i = 0; i < n; ++i)
        if(!i || P[i] != P[i-1]) {
            int c1 = 0, c2 = 0;
            for(int j = 0; j < cur; ++j) 
                if(A[j] == P[i]) c1++;

            for(int j = 0; j < n; ++j) 
                if(P[i] == P[j]) c2++;

            if (c1 < c2) {
                A[cur] = P[i];
                print_permutation(n, P, A, cur + 1);
            }
        }

int main() {
    int n, p[10];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &p[i]);
    sort(p, p + n);
    do {
        for(int i = 0; i < n; ++i) printf("%d ", p[i]);
        printf("\n");
    } while(next_permutation(p, p + n));
    return 0;
}
