//
// @Time   : 2021/1/16 12:51
// @Author : junstat@163.com

#ifndef POSTGRADUATEADMISSIONTEST_DLINKLIST_H
#define POSTGRADUATEADMISSIONTEST_DLINKLIST_H

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    DNode *prior, *next;
} DNode, *DLinkList;

#endif //POSTGRADUATEADMISSIONTEST_DLINKLIST_H
