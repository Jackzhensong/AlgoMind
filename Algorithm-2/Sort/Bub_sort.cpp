
//冒泡排序，稳定排序
void bubblesort(int A[], int size)
{
    bool change = true;
    for (int i = size - 1; i > 0 && change; --i)
    {
        change = false;
        for (int j = 0; j < i; ++j)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                change = true;
            }
        }
    }
}

void bubblesort(int A[], int n)
{
    for (bool sorted = false; sorted = !sorted; n--) // 此处 = 是赋值意思
        for (int i = 1; i < n; ++i)
            if (A[i - 1] > A[i])    // 若逆序，则交换
            { 
                swap(A[i - 1], A[i]);
                sorted = false;     // 清除有序标志
            }
}


/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    bubblesort(a, n);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    return 0;
}
*/