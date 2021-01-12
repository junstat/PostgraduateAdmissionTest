//
// @Time   : 2021/1/13 21:15
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   递归: 每当访问一个结点时，先递归输出它后面的结点，再输出该结点自身。
 */
void R_Print(LinkList L) {
    if (L == NULL) return;
    else {
        R_Print(L->next);
        printf("%d ", L->data);
    }
}
