//
// @Time   : 2021/1/15 00:08
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   用p扫描L，若*p结点的值域等于其后继结点的值域，则删除后者，否则p移向下一个结点。
 */
void Del_Same(LinkList &L) {
    // L是递增有序的单链表，删除表中数值相同的元素
    LNode *p = L->next, *q; // p为工作指针，q为p后继
    if (p == NULL) return;
    while (p->next) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else p = p->next;
    }
}