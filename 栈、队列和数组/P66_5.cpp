//
//
//

#define MaxSize 100

typedef struct{
    ElemType data[MaxSize];    // 存储区
    int top[2];                // 栈顶指针
}SharedStack;

bool push(SharedStack& S, int t, ElemType x)
{
    // 共享栈满，无法插入
    if(S.top[1] - S.top[0] == 1)
        return false;
    
    if(t == 0)    // [push][]
        S.data[++S.top[0]] = x;
    if(t == 1)    // [][push]
        S.data[--S.top[1]] = x;
    return true;
}

bool pop(SharedStack& S, int t, ElemType& x)
{
    if(t == 0 && S.top[0] >= 0)
    {
        x = S.data[S.top[0]--];
        return true;
    }
    if(t == 1 && S.top[1] <= MaxSize)
    {
        x = S.data[S.top[1]++];
        return true;
    }
    return false;
}


