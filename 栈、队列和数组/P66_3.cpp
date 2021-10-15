//
// 写一个算法，判定所给的操作序列是否合法。若合法，返回true，否则返回false
// (假定被判定的操作序列以及存入一维数组)
//

bool Legal_Squence(char arr[], int n)
{
    int num = 0;    // 栈中元素个数
    int k = 0;      // 遍历数组下标
    while(k < n)
    {
        if(arr[k] == 'I')
            num++;
        if(arr[k] == 'O')
            num--;
        if(num < 0) // 栈空出栈
            return false;
        k++;
    }
    
    if(num != 0)    // 栈终态不为空，返回false
        return false;
    return true;
}
