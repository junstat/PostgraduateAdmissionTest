//
// @Time   : 2021/1/15 00:34
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   采用归并思想，设置两个工作指针pa和pb，对两个链表进行归并扫描，只有同时出现在两集合中的元素才链接到结果表中且保留一个，其他的结点全部释放。
   当一个链表遍历完毕，释放另一个表中剩下的全部结点。
 */
LinkList Union(LinkList &la, LinkList &lb) {
    LNode *pa = la->next, *pb = lb->next, *pc = la, *u;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
        } else {
            u = pb;
            pb = pb->next;
        }
        free(u);
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
}
