//
// @Time   : 2021/1/16 12:57
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   先找到两个链表的尾指针，将第一个链表的尾指针与第二个链表的头结点链接起来，再使之成为循环的
 */
LinkList Link(LinkList &h1, LinkList &h2) {
    // 将循环链表h2链接到循环链表h1之后，使之仍保持循环链表的形式
    LNode *p, *q;
    p = h1;
    while (p->next != h1) p = p->next;
    q = h2;
    while (q->next != h2) q = q->next;
    p->next = h2;
    q->next = h1;
    return h1;
}