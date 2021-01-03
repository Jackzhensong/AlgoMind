
 //快速排序，不稳定算法
 void Quicksort(int *A, int s, int e) {
     if (s < e) {
         int k = A[s];
         int i = s, j = e;
         while (i < j) {
             while (i < j && A[j] >= k) --j;
             swap(A[i], A[j]);

             while (i < j && A[i] <= k) ++i;
             swap(A[i], A[j]);
         }
         Quicksort(A, s, i - 1);
         Quicksort(A, i + 1, e);
     }
     return;
 }

 void Quicksort(int *A, int low, int high) {
     if (low < high) {
         int k = A[low];
         int i = low, j = high;
         while (i < j) {
             while (i < j && A[j] >= k) --j;
             A[i] = A[j];

             while (i < j && A[i] <= k) ++i;
             A[j] = A[i];
         }
         A[i] = k;
         Quicksort(A, low, i - 1);
         Quicksort(A, i + 1, high);
     }
     return;
 }

/*
#include<iostream>
using namespace std;
int num;
int ans;

int main() {
    //cin >> num;
    int A[] = {2, 4, 1, 9, 5, 3, 3};
    Quicksort(A, 0, 6);
    
    for (int i = 0; i < 7; ++i) 
        cout << A[i] << " ";
    //ans = A[num - 1];
    //cout << ans << endl;
    return 0;
}

    if(num == i + 1) {ans = A[i];  return;}
    else if(num < i + 1) Quicksort(A, s, i);
    else if(num > i + 1) Quicksort(A, i + 1, e);

*/


