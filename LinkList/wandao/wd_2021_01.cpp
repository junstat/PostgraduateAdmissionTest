//
// @Time   : 2021/1/12 22:21
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   设f(L, x)的功能是删除以L为首结点的链表中所有值为x的结点，递归模型如下:
   终止条件: 不做任何事,  若L为空表
   递归主体:
        删除*L结点；f(L -> next, x); 若 L -> data == x
        f(L -> next, x);     若 L -> data != x

    算法需要借助一个递归工作栈，深度为O(n)，时间复杂度为O(n)。
 */
void Del_X_3(LinkList &L, ElemType x) {
    // 递归实现在单链表L中删除值为x的结点
    if (L == NULL) return;  // 递归出口
    if (L->data == x) {
        LNode *p = L;  // 暂存L
        L = L->next;
        free(p);        // 释放L
        Del_X_3(L, x);  // 递归调用
    } else Del_X_3(L->next, x);
}