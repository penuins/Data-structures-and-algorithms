//
// 删除顺序表中值重复的元素
//

void Del_Rep(SqList& L)
{
    // 双指针法
    int slow = fast = 0;
    
    while(fast < L.length)
    {
        // 若当前元素不重复，则加入到新顺序表中
        if(L.data[fast + 1] != L.data[slow])
            L.data[++slow] = L.data[++fast];
        // 否则处理下一个元素
        else
            ++fast;
    }
    
    // 更新顺序表表长
    L.length = slow + 1;
}



