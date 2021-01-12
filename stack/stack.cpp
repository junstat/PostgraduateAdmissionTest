//
// Created by jun on 2021/1/12.
//
#include <iostream>
#include "stack.h"

using namespace std;


/**
 * 初始化
 * @param S
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * 判空
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

/**
 * 入栈
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1) return false; // 栈满
    S.data[++S.top] = x;
    return true;
}

/**
 * 出栈
 * @param S
 * @param x
 * @return
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;  // 栈空
    x = S.data[S.top--];
    return true;
}

/**
 * 获取栈顶元素
 * @param S
 * @param x
 * @return
 */
bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1) return false; // 栈空
    x = S.data[S.top];
    return true;
}