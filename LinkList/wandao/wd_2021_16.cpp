//
// @Time   : 2021/1/15 00:42
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   因为两个整数序列已存入两个链表中，操作从两个链表的第一个结点开始，若对应数据相等，则后移指针；若对应数据不等，则A链表中上次开始比较结点的后继
   开始，B链表仍从第一个结点开始比较，直到B链表到尾表示匹配成功。A链表到尾而B链表未到尾表示失败。操作中应记得A链表每次的开始结点，以便下次匹配时
   好从其后继开始。
 */
int Pattern(LinkList A, LinkList B) {
    LNode *p = A, *pre = p, *q = B;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    if (q == NULL) return 1;
    else return 0;
}

