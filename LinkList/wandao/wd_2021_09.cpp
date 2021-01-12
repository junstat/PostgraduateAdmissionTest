//
// @Time   : 2021/1/13 22:49
// @Author : junstat@163.com

#include "wd_2021.h"

void Min_Delete(LinkList &head) {
    // 按递增序输出单链表中的元素，之后释放结点
    LNode *pre, *p, *u;  // p为工作指针，pre为p前驱
    while (head->next) {
        pre = head;
        p = pre->next;
        while (p->next) {
            if (p->next->data < pre->next->data)
                pre = p;
            p = p->next;
        }
        printf("%d ", pre->next->data);
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(head);
}

