//
// @Time   : 2021/1/16 17:57
// @Author : junstat@163.com

#include "wd_2021.h"

/*
   1) 算法的基本设计思想
    设置快慢两个指针分别为fast和slow，初始化时都指向链表头head。slow每次走一步，fast每次走两步。由于fast比slow走得快，如果有环，fast一定先
    进入环，而slow后进入环。当两个指针都进入环后，经过若干次操作后两个指针定能在环上相遇。
    设头结点到环入口点的距离为a，环的入口点沿着环的方向到相遇点的距离为x，环长为r，相遇时fast绕过了n圈。
    则，慢针走过的距离为a+x，因为快针的速度是慢针的2倍，所以，快针走过了 2(a+x)
    又从环内的角度看，快针走过了非环a，n圈 n*r，相遇点x => 快针走过了 a + n*r + x
    故 2(a+x) = a + n*r +x => a = n*r -x。
    显然从头结点到环的入口点的距离等于n倍的环长减去环的入口点到相遇点的距离。因此可设置两个指针，一个指向head，一个指向相遇点，两个指针同步移动，
    相遇点即为环的入口点。
 */
LNode *FindLoopStart(LNode *head) {
    LNode *fast = head, *slow = head;   // 设置快慢针
    while (slow && fast->next) {
        slow = slow->next;          // 慢针每次走一步
        fast = fast->next->next;    // 快针每次走两步
        if (slow == fast) break;    // 相遇
    }
    if (slow == NULL || fast->next == NULL) return NULL;    // 没有环
    LNode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;  // 找到了入口点
}