//
// @Time   : 2021/1/13 22:56
// @Author : junstat@163.com

#include "wd_2021.h"

LinkList DisCreate_1(LinkList &A) {
    // 将表A中结点按序号的奇偶性分解到表A或表B中
    int i = 0;
    LinkList B = (LinkList) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B, *p = A->next;
    A->next = NULL;

    while (p) {
        i++;
        if (i % 2 == 0) {
            rb->next = p;
            rb = rb->next;
        } else {
            ra->next = p;
            ra = ra->next;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}
