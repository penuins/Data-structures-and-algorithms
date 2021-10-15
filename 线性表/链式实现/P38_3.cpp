//
// 设L为带头结点的单链表，编写算法实现从头到尾反向输出每个结点的值
//

void ReverseOutput(LinkList L)
{
    if(L->next == NULL)    // 边界条件
        return;
    
    L = L->next;
    if(L != NULL)
        ReverseOutput(L->next);
    print(L->data);
}

