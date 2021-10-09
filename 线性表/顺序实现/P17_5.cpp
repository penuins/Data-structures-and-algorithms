//
// 从顺序表中删除值在s和t之间的元素，其中s<t
//

bool Del_s_t(SqList& L, int s, int t)
{
    // 参数合法性检查
    if(s >= t)
        return false;
    
    // 双指针法
    int slow = fast = 0;
    while(fast < L.length)
    {
        if(L.data[fast] < s || L.data[fast] > t)
            L.data[slow++] = L.data[fast];
        fast++;
    }
    
    // 更新顺序表长度
    L.length = slow + 1;
    return true;
}
