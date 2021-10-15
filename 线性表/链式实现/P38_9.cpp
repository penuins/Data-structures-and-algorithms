//
// 给定一个带表头结点的单链表，设head为头指针，结点结构为(data, next)，data为整型元素，next为指针
// 试写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
// (不允许使用数组作为辅助空间)
//

void Increase_Output(LNode* head)
{
    // 对单链表进行直接插入排序
    LNode* p = head->next;
    head->next = NULL;
    
    while(p != NULL)
    {
        LNode* s = p;
        p = p->next;
        
        // 寻找插入位置
        LNode* q = head;
        while(q->next != NULL)
        {
            if(q->next->data <= s->data)
                q = q->next;
        }
        
        // 将结点s插入
        s->next = q->next;
        q->next = s;
    }
    
    // 按递增次序输出结点并删除
    while(head->next != NULL)
    {
        print(head->next->data);
        p = head->next;
        head->next = head->next->next;
        free(p);
    }
}

