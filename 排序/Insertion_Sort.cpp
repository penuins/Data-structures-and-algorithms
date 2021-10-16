//
// 直接插入排序
//

void Insertion_Sort(int arr[], int n)
{
    // 外层循环，i指向当前处理的数组元素下标
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i;
        // 内层循环，j指向当前正在与key比较的元素的下一个位置
        while(j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

//
// 直接插入排序(递归实现)
//

void Insertion_Sort(int arr[], int n, int i)
{
    if(i == n)    // 边界条件
        return;
    int key = arr[i];
    int j = i;
    while(j > 0 && arr[j - 1] > key)
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[j] = key;
    // 进行递归
    Insertion_Sort(arr, n, i + 1);
}



