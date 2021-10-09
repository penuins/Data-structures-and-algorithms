//
// 从有序顺序表中值在s到t之间的元素，要求s<t
//

bool Del_s_t(SqList& L, int s, int t)
{
    // 参数合法性检查
    if(s >= t)
        return false;
    
    // 找到要删除的连续元素序列
    int start = end = 0;
    while(L.data[start] < s)
        start++;
    end = start;
    while(L.data[end] < t)
        end++;

    // 覆盖被删除的元素
    int i = start, j = end;
    while(i < end && j < L.length)
        L.data[i++] = L.data[j++]
    
    // 更新顺序表长度
    L.length = L.length - (end - start);
    return true;
}
