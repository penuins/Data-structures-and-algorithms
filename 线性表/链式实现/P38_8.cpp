//
// 给定两个单链表，编写算法找出两个链表的公共结点
//

//
// 由于单链表的结点只有一个next域，如果结点s是链表A和链表B的公共结点，则后续结点也是A和B的公共结点
//

LNode* Common_Node(LinkList A, LiskList B)
{
    LNode* a = A->next;
    while(a != NULL)
    {
        LNode* b = B->next;
        while(b != NULL)
        {
            if(a->next != b->next)
                b = b->next;
            else
                return a->next;
        }
        a = a->next;
    }
    return NULL;
}
