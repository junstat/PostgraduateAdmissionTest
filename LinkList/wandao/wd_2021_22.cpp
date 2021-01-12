//
// @Time   : 2021/1/16 16:15
// @Author : junstat@163.com

#include <cstdio>
#include <cstdlib>

/*
   1) 算法的基本设计思想如下:
     1. 分别求出str1和str2所指的两个链表的长度m和n
     2. 将两个链表以表尾对齐: 令指针p、q分别指向str1和str2的头结点，若m >= n，则指针p先走，使p指向链表中的第m-n+1个结点；若m<n，则使q指向链
     表中的第n-m+1个结点，即使指针p和q所指的结点到表尾的长度相等。
     3. 反复将指针p和q同步向后移动，当p、q指向同一位置时停止，即为共同后缀的起始位置。
   2) 代码如下；
   3) 时间复杂度为O(len1 + len2)或O(max(len1, len2))，其中len1、len2分别为两个链表的长度。
 */
typedef struct Node {
    char data;
    struct Node *next;
} SNode;

int list_len(SNode *head) {
    // 求链表的长度
    int len = 0;
    while (head->next) {
        len++;
        head = head->next;
    }
    return len;
}

SNode *find_addr(SNode *str1, SNode *str2) {
    // 找到共同后缀的起始地址
    int m, n;
    SNode *p, *q;
    m = list_len(str1);
    n = list_len(str2);
    for (p = str1; m > n; m--) p = p->next;
    for (q = str2; m < n; n--) q = q->next;
    while (p->next && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}
