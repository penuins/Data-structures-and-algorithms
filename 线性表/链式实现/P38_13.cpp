//
// 13. 两升序单链表原地归并为一个降序单链表
//
// 假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。
// 请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个链表的结点存放归并后的单链表
//

// 假设两个单链表都不带头结点(不然归并后多出来一个头结点)
void Merge_Lists(LinkList& A, LinkList& B, LinkList& C)
{
    LNode* a = A;    // 遍历表A的指针
    LNode* b = B;    // 遍历表B的指针
    LNode* s = NULL;
    while(a != NULL && b !=NULL)
    {
        if(a->data <= b->data)
        {
            s = a;
            a = a->next;
        }
        else
        {
            s = b;
            b = b->next;
        }
            s->next = C;
            C = s;
    }
    
    // 表A未空
    while(a != NULL)
    {
        s = a;
        a = a->next;
        
        s->next = C;
        C = s;
    }
    // 表B未空
    while(b != NULL)
    {
        s = b;
        b = b->next;
        
        s->next = C;
        C = s;
    }
}
