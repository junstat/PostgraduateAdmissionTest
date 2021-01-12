//
// @Time   : 2021/1/13 21:43
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   方法一: 遍历，逐个摘下结点，头插到新链表
 */
LinkList Reverse_1(LinkList L) {
    LNode *p, *r;   // p为工作指针，r为p后继，防断链
    p = L->next;
    L->next = NULL;
    while (p) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}

/*
   设pre、p和r指向3个相邻的结点，假设经过若干的操作后，pre之前的结点指针都已调整完毕。
   现在令p结点的next域指向pre，注意到一旦调整指针的指向后，p的后继结点就会断链，为此
   需要用r来指向原p的后继。
   注意: 1. 在处理第一个结点时，应将其next域置为NULL，而不是指向头结点(因为它是结果
   链表的尾结点);
   2. 在处理完最后一个结点后，需要将头结点的指针指向它。
 */
LinkList Reverse_2(LinkList L) {
    // 依次遍历L，并将结点指针反转
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL; // 注意1
    while (r) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;    // 注意2
    return L;
}

