//
// 数组a[m+n]逆置为a[n+m]
//

void Rotate(int arr[], int m, int n)
{
    Reverse(arr, 0, m - 1);
    Reverse(arr, m, m + n - 1);
    Reverse(arr, 0, m + n - 1);
}

void Reverse(int arr[], int left, int right)
{
    while(left < right)
        swap(arr[left], arr[right]);
}

void swap(int* a, int* b)
{
    int temp = a;
    a = b;
    b = temp;
}


