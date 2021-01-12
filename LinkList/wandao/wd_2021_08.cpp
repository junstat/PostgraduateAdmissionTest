//
// @Time   : 2021/1/13 22:36
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   若L1, L2存在公共结点，则公共结点之后所有结点共用。
   算法: 先对齐长度，较长的链表先走 长度差 步，之后同步遍历，第一个相同的结点即为所求。
   时间复杂度: O(n^2)
 */
LinkList Search_1st_Common(LinkList L1, LinkList L2) {
    // 在线性的时间内找到两个单链表的第一个公共结点
    int len1 = Length(L1), len2 = Length(L2), dist = len1 > len2 ? len1 - len2 : len2 - len1;
    LinkList longList = L1->next, shortList = L2->next;
    if (len1 < len2) {
        longList = L2->next;
        shortList = L1->next;
    }
    while (dist--) longList = longList->next;
    while (longList) {
        if (longList == shortList) return longList;
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}