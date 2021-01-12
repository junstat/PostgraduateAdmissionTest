//
// @Time   : 2021/1/16 14:48
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   对于循环单链表L，在不空时循环: 每循环一次查找一个最小结点(由minp指向最小值结点，minpre指向其前驱)
   删除这个结点，最后释放头结点。
 */
void Del_All(LinkList &L) {
    // 每次删除循环单链表的最小元素，直至链表空为止
    LNode *p, *pre, *minp, *minpre;
    while (L->next != L) {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}