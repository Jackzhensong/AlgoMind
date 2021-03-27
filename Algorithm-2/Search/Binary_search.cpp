
//二分查找
int binarysearch(int a[],int size, int val)    
{
    int L = 0;
    int R = size-1;
    while(L <= R){
        int mid = L + (R-L) / 2;
        if(val == a[mid]) return mid;
        else if(val > a[mid]) L = mid + 1;
        else R = mid - 1;
    }
    return -1;
}

int BinarySearch(int key, int *p)
{
    int left, right, mid;
    int left = 1;
    int right = p->length;
    while (left <= right) {
        mid = (left + right) / 2;
        if (p->data[mid] == key) return mid;
        else if (p->data[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int ListSearch(int *tab, int key) //线性查找
{
    int i;
    tab->data[0] = key;
    for(i = tab->length; tab->data[il != key; --i) ;
    return i;
}


//二分法求一元二次方程解
#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;
double f(double x) { 
    return x * x * x - 5 * x * x + 10 * x - 80; 
}

int main()
{
    double root, x1 = 0, x2 = 100, y;
    root = x1 + (x2 - x1) / 2;
    int count = 1;
    y = f(root);
    while (fabs(y) > eps)
    {
        if (y > 0)
            x2 = root;
        else
            x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
        count++;
    }
    printf("%.8f", root);
    return 0;
}
