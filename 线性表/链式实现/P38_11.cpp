//
// 设C={a1, b1, a2, b2, ..., an, bn}为线性表，采用带头结点的hc单链表存放，设计一个算法，将其拆分为两个线性表，使得A={a1, a2, ..., an}，B={b1, b2, ..., bn}
//

void Split_List(LinkList& C, LinkList& A, LinkList& B)
{
    int flag = 0;        // 当前处理的元素应放到哪个链表
                         // flag=0表示应放到A中
                         // flag=1表示应放到B中
    
    LNode* p = L->next;
    while(p != NULL)
    {
        // 摘下结点p
        L->next = p->next;
        
        // 插入到链表A
        if(flag == 0)
        {
            p->next = A->next;
            A->next = p;
            flag = 1;
        }
        // 插入到链表B
        else
        {
            p->next = B->next;
            B->next = p;
            flag = 0;
        }
        
        // 更新p
        p = L->next;
    }
}
