//
// 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值之间的元素的元素
//

void Delete_a_b(LinkList& L, ElemType a, ElemType b)
{
    LNode* p = L;
    LNode* q = L->next;
    
    while(q != NULL)
    {
        // 如果q结点元素介于a和b之间，则删除
        if(a < q->data && q->data < b)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        // 否则检查后续位置
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}
