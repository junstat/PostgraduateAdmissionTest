//
// @Time   : 2021/1/13 22:26
// @Author : junstat@163.com

#include "wd_2021.h"

void RangeDelete(LinkList &L, int start, int end) {
    // 删除[start, end]范围内的结点，遍历
    LNode *p = L->next, *pre = L;
    while (p) {
        if (start <= p->data && p->data <= end) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}