//
// 在顺序表中高效寻找x，若找到则交换其与直接后继的位置，若未找到则将其插入到顺序表中并使表保持有序
//

void Find_x(SqList& L, int x)
{
    int mid = 0;
    int left = 0;
    int right = L.length - 1;
    
    // 在顺序表中二分查找x
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(L.data[mid] == x)
            swap(L.data[mid], L.data[mid + 1]);
    }
    
    // 若未找到，则将x插入并使只保持有序
    if(L.data[mid] != x)
        for(int i = L.length; i > mid; i--)
            L.data[i] = L.data[i - 1];
    L.data[mid] = x;
}

