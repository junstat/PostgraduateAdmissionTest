//
// @Time   : 2021/1/12 22:31
// @Author : junstat@163.com

#include "wd_2021.h"

/*
    解法一: 遍历L, p为遍历当前结点，pre为p前驱，若p所指结点的值为x，则删除，并让p移向下一个结点，否则让pre、p同步后移。
 */
void Del_X_1(LinkList &L, ElemType x) {
    // L为带头结点的单链表，删除L中所有值为x的结点
    LNode *p = L->next, *pre = L, *q;
    while (p) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/*
   解法二: 遍历L，逐结点从L上摘下，若结点值不等于x，则采用尾插法链接到新链表。
 */
void Del_X_2(LinkList &L, ElemType x) {
    LNode *p = L->next, *r = L, *q;     // r指向尾结点
    while (p) {
        if (p->data != x) {
            r->next = p;
            r = p;
        } else {
            q = p;
            free(q);
        }
        p = p->next;
    }
}

