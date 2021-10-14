//
//
//

bool isAvailable(char A[], int n)
{
    int count = 0;    // 栈中元素的个数
    int k = 0;
    while(k < n)
    {
        if(A[k] == 'I')
            count++;
        elseif(A[k] == 'O')
            count--;
        
        if(count < 0)
            return false;
        k++;
    }
    if(count == 0)
        return true;
    else
        return false;
}
