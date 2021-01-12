//
// Created by jun on 2021/1/12.
//

#include <iostream>
#include "LinkList.h"

using namespace std;

/**
 * 头插法建立带头结点的单链表
 * 时间复杂为O(n)
 * 拓展: 若没有头结点
 * @param L
 * @return
 */
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 尾插法建立单链表
 * @param L
 * @return
 */
LinkList List_TailInset(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

/**
 * 按序号查找
 * @param L
 * @param i
 * @return
 */
LNode *GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查找
 * @param L
 * @param e
 * @return
 */
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

/**
 * 在第i位序插入结点
 * @param L
 * @param i
 * @return
 */
bool Insert(LinkList &L, int x, int i) {
    LNode *p = GetElem(L, i - 1);
    LNode *s;
    if (p != NULL) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return true;
    }
    return false;
}

/**
 * 删除结点
 * @param L
 * @param i
 * @return
 */
bool Delete(LinkList &L, int i) {
    LNode *p = GetElem(L, i - 1);
    if (p != NULL) {
        LNode *q = p->next;
        p->next = q->next;
        free(q);
        return true;
    }
    return false;
}

/**
 * 计算链表长度
 * @param L
 * @return
 */
int Length(LinkList L) {
    if (!L || !L->next) return 0;
    int len = 1;
    for (LNode *p = L->next; p != NULL; p = p->next)
        len++;
    return len;
}

void travel(LinkList L) {
    LNode *p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
