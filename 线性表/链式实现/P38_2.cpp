//
// 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作
//

void Del_All_x(LinkList& L, ElemType x)
{
    LNode* p = L, q = L->next;
    while(q != NULL)
    {
        if(q->data == x)    // 删除结点q
        {
            p->next = q->next;
            q->next = NULL;
            free(q);
            q = p->next;
        }
        else                // 指针后移
        {
            p = p->next;
            q = q->next;
        }
    }
}


