//
// @Time   : 2021/1/15 00:27
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   表A、B都有序，可从第一个元素起依次比较A、B两表的元素，若元素值不等，则值小的指针往后移，若元素值相等，则创建一个值等于两结点的元素值的新结点，
   使用尾插法插入到新的链表中，并将两个原表指针后移一位，直到其中一个链表遍历到表尾。
 */
void Get_Common(LinkList A, LinkList B) {
    // 产生A和B的公共元素的表C
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList) malloc(sizeof(LNode));
    r = C;
    while (p && q) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            s = (LNode *) malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
}