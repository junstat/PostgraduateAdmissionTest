//
// @Time   : 2021/1/16 15:02
// @Author : junstat@163.com

#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *pred, *next;
    int freq = 0;
} DNode, *DLinkList;

/*
   首先在双向链表中查找数据值为x的结点，查到后，将结点从链表上摘下，然后再顺着结点的前驱链查找改结点的插入位置(频度递减，且排在同频度的第一个，
   即向前找到第一个比它的频度大的结点，插入位置为该结点之后)，并插入到该位置。
 */
DLinkList Locate(DLinkList &L, ElemType x) {
    // 先查找数据，查找成功时结点的访问频度域增1
    // 最后将该结点按频度递减插入链表中适当位置(同频度最近访问的在前面)
    DNode *p = L->next, *q;    //  p为工作指针，q为p的前驱，用于查找插入位置
    while (p && p->data != x) p = p->next;
    if (!p) {
        printf("不存在值为x的结点\n");
        exit(0);
    } else {
        p->freq++;
        if (p->next != NULL) p->next->pred = p->pred;
        p->pred->next = p->next;
        q = p->pred;
        while (q != L && q->freq <= p->freq) q = q->pred;
        p->next = q->next;
        q->next->pred = p;
        p->pred = q;
        q->next = p;
    }
    return p;
}
