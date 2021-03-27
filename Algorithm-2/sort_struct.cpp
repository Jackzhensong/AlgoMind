#include <bits/stdc++.h>
using namespace std;

struct rule1
{
    bool operator()(const int &a1, const int &a2)
    {
        return a1 > a2; //从大到小排序
    }
};

struct rule2
{
    bool operator()(const int &a1, const int &a2)
    {
        return a1 % 10 > a2 % 10; //按个位数从大到小排序
    }
};

void print(int a[], int size)
{
    for (int i = 0; i < size; i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {12, 45, 3, 98, 21, 7};
    sort(a, a + sizeof(a) / sizeof(int));
    cout << "1) ";
    print(a, sizeof(a) / sizeof(int));
    sort(a, a + sizeof(a) / sizeof(int), rule1());
    cout << "2) ";
    print(a, sizeof(a) / sizeof(int));
}