//
// Created by jun on 2021/1/12.
//
#include "wd_2021.h"

typedef struct node {
    int data;
    struct node *next;
} NODE;

void change_list(NODE *h) {
    NODE *p, *q, *r, *s;
    p = q = h;
    while (q->next != NULL) {  // 寻找中间结点
        p = p->next;    // p 走一步
        q = q->next;
        if (q->next != NULL) q = q->next;  // q走两步
    }
    q = p->next;    // p所指结点为中间结点，q为后半段链表的首结点
    p->next = NULL;
    while (q != NULL) { // 将链表后半段逆置
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = h->next;    // s 指向前半段的第一个数据点，即插入点
    q = p->next;    // q 指向后半段的第一个数据结点
    p->next = NULL;
    while (q != NULL) { // 将链表后半段的结点插入到指定位置
        r = q->next;     // r指向后半段的下一个结点
        q->next = s->next;  // 将q所指结点插入到s所指结点之后
        s->next = q;
        s = q->next;  // s指向前半段的下一个插入点
        q = r;
    }
}