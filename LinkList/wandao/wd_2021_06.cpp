//
// @Time   : 2021/1/13 21:58
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   链表插入排序
 */
void Sort(LinkList &L) {
    // 空表或只有一个元素，无需排序
    if (!L || !L->next || !L->next->next) return;
    LNode *r = L->next; // 保存有序部分的最后一个结点
    LNode *p = L->next->next; // 第1个元素默认有序，从第2个数据结点开始
    while (p) {
        if (r->data <= p->data) { // 有序
            r = p;
        } else {
            LNode *pre = L;
            while (pre->next->data < p->data) // 从有序部分第1个结点开始找插入位置
                pre = pre->next;
            r->next = p->next;  // 将p摘下，保证不断链
            p->next = pre->next;  // 将p挂在pre后
            pre->next = p;
        }
        p = r->next;
    }
}

