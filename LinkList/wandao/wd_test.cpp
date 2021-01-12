//
// @Time   : 2021/1/13 22:16
// @Author : junstat@163.com

#include "wd_2021.h"

void test_06() {
    LinkList L;
    List_TailInset(L);
    printf("原链表: \n");
    travel(L);
    Sort(L);
    printf("排序后: \n");
    travel(L);
}

void test_13() {
    LinkList La, Lb;
    List_TailInset(La);
    List_TailInset(Lb);
    printf("La: ");
    travel(La);
    printf("Lb: ");
    travel(Lb);
    MergeList(La, Lb);
    printf("合并后: ");
    travel(La);
}

int main() {
    test_13();
    return 0;
}