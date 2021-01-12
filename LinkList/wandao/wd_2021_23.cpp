//
// @Time   : 2021/1/16 16:45
// @Author : junstat@163.com
#include <cstdio>
#include <cstdlib>

/*
   1) 算法的基本设计思想，用空间换时间
     1. 使用辅助数组记录链表中已出现的数值，从而只需到链表进行一趟扫描。
     2. 因为|data| <=n，故辅助数组q的大小为n+1，各元素的初值均为0。依次扫描链表中的各结点，同时检查q[|data|]的值，若为0则保留该结点，并
      令q[|data|]=1；否则将该结点从链表中删除。
 */

typedef struct node {
    int data;
    struct node *link;
} NODE, *PNODE;

void func(PNODE h, int n) {
    PNODE p = h, r;
    int *q, m;
    q = (int *) malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; i++) *(q + i) = 0;
    while (p->link) {
        m = p->link->data > 0 ? p->link->data : -p->link->data;
        if (*(q + m) == 0) {
            *(q + m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p->link = r->link;
            free(r);
        }
    }
    free(q);
}