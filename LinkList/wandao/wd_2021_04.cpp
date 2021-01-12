//
// @Time   : 2021/1/13 21:28
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   找minp, 及其前驱pre
 */
LinkList Delete_Min(LinkList &L) {
    // L是带头结点的单链表，删除其最小值
    LNode *p = L->next, *pre = L, *minP = p, *minPre = pre;
    while (p) {
        if (p->data < minP->data) {
            minP = p;
            minPre = pre;
        }
        pre = p;
        p = p->next;
    }
    minPre->next = minP->next;
    free(minP);
    return L;
}
