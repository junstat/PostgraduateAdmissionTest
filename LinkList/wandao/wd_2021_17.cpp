//
// @Time   : 2021/1/16 12:53
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   让p从左往右扫描，q从右往左扫描；遍历，q，p结点值不等则false；否则true；
 */
int Symmetry(DLinkList L) {
    // 从两头扫描循环双链表，以判断链表是否对称
    DNode *p = L->next, *q = L->prior;
    while (p != q && q->next != p) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else return 0;
    }
    return 1;
}