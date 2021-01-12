//
// @Time   : 2021/1/14 23:55
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   头插常规操作，以p，插入B为例: p->next = B->next; B->next = p;
 */
LinkList DisCreat_2(LinkList &A) {
    LinkList B = (LinkList) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next, *q;     // p为工作指针
    LNode *ra = A;      // A尾结点
    while (p) {
        ra->next = p;
        ra = p;
        p = p->next;
        if (p) q = p->next;
        p->next = B->next;  // 头插后，*p将断链，因此用q记忆*p的后继
        B->next = p;    // 将*p插入到B的前端
        p = q;
    }
    ra->next = NULL;    // A尾结点的next域置空
    return B;
}
