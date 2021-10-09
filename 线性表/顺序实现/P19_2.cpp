//
// 逆置顺序表的所有元素
//

void Reverse_x(SqList& L)
{
    int left = 0;                // 最左端
    int right = L.length - 1;    // 最右端
    while(left < right)
        swap(L.data[left], L.data[right]);
}

void swap(int* a, int* b)
{
    int temp = a;
    a = b;
    b = temp;
}

//
// 更一般的，逆置顺序表从left到right部分的数据元素
//

void Reverse(SqList& L, int left, int right)
{
    while(left < right)
        swap(L.data[left], L.right[right]);
}
