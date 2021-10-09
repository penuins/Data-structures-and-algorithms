//
// 将两个有序顺序表合并为一个有序顺序表哦
//

bool Merge(SqList A, SqList B, SqList& C)
{
    C.length = A.length + B.length;
    if(C.length > MaxSize)
        return false;
    
    // i：正在遍历表A的下标
    // j：正在遍历表B的下标
    // k：满足条件的元素要放到表C的位置
    int i = j = k = 0;
    
    // 两顺序表都没有添加完时，依次比较大小并添加
    while(i < A.length && j < B.length)
    {
        if(A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    
    // 将剩余的顺序表添加到新表中
    while(i < A.length)
        C.data[k++] = A.data[i++];
    while(j < B.length)
        C.data[k++] = B.data[j++];
    
    return true;
}



