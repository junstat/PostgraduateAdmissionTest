//
// @Time   : 2021/1/16 15:12
// @Author : junstat@163.com
#include <cstdio>

typedef int ELemType;
typedef struct LNode {
    ELemType data;
    struct LNode *link;
} LNode, *LinkList;

/*
   1) 算法基本设计思想如下:
   问题的关键是设计一个尽可能高效的算法，通过链表的一次遍历，找到倒数第k个结点的位置。算法的基本设计思想是：定义两个指针变量p和q，初始时均指向头
   结点的下一个结点(链表的第一个结点)，p指针沿链表移动；当p指针移动到第k个结点时，q指针开始与p指针同步移动；当p指针移动到最后一个结点时，q指针
   所指示结点为倒数第k个结点。
   2) 算法的详细实现步骤如下:
   1. count = 0, p 和 q指向链表表头结点的下一个结点。
   2. 若p为空，转5.
   3. 若count等于k，则q指向下一个结点；否则, count+=1；
   4. p指向下一个结点，转2.
   5. 若count等于k，则查找成功，输出该结点的data域的值，返回1；否则，说明k值超过了线性表的长度，查找失败，返回0.
   6. 算法结束
 */
int Search_k(LinkList list, int k) {
    // 查找链表list倒数第k个结点，并输出该结点data域的值
    LNode *p = list->link, *q = list->link;
    int count = 0;
    while (p) {
        if (count < k) count++;
        else q = q->link;
        p = p->link;
    } // end of while
    if (count < k) return 0;
    else {
        printf("%d", q->data);
        return 1;
    }
}