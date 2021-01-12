//
// Created by jun on 2021/1/12.
//

#ifndef POSTGRADUATEADMISSIONTEST_LINKLIST_H
#define POSTGRADUATEADMISSIONTEST_LINKLIST_H

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_TailInset(LinkList &L);

void travel(LinkList L);

int Length(LinkList L);

int Pattern(LinkList A, LinkList B);

#endif //POSTGRADUATEADMISSIONTEST_LINKLIST_H
