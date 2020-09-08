
//选择排序，不稳定排序
void selectsort(int a[], int size) 
{
    for (int i = 0; i < size - 1; ++i) {

        int key = i;        // 记录最小元素的下标
        for (int j = i + 1; j < size; ++j)
            if (a[j] < a[key])  key = j;
            
        swap(a[i], a[key]);
    }
}

