//
// 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
//

void Del_x(LinkList& L, ElemType x)
{
    if(L == NULL)      // 边界条件
        return;
    
    if(L->data == x)   // 当前元素等于x
    {
        LNode* p = L;
        L=L->next;
        free(p);
        Del_x(L, x);
    }
    else               // 当前元素不等于x
        Del_x(L->next, x);
}
