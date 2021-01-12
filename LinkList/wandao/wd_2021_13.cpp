//
// @Time   : 2021/1/15 00:12
// @Author : junstat@163.com

#include "wd_2021.h"

void MergeList(LinkList &La, LinkList &Lb) {
    // 合并两个递增有序链表(带头结点)，并使合并后的链表递减排列
    LNode *pa = La->next, *pb = Lb->next, *r;
    La->next = NULL;  // 作为结果链表
    while (pa && pb) {
        if (pa->data < pb->data) {
            r = pa->next;   // 后续把pa头插到La，要把pa先摘下，必将断链，先暂存pa->next到r
            pa->next = La->next;
            La->next = pa;
            pa = r;
        } else {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa) pb = pa;
    while (pb) {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}
