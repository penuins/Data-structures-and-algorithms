//
// 删除线性表中所有值为x的元素
//

void Del_x(SqList& L, ElemType x)
{
    // 双指针法
    // slow：下一个元素应当插入的数组下标
    // fast：正在遍历的数组下标
    int slow = fast = 0;
    while(fast < L.length)
    {
        if(L.data[fast] != x)
            L.data[slow++] = L.data[fast];
        fast++;
    }
    // 更新顺序表表长
    L.length = slow + 1;
}

