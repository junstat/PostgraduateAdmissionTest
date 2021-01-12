//
// @Time   : 2021/1/13 00:57
// @Author : junstat@163.com

#include <iostream>
#include "String.h"

using namespace std;


bool SubString(SString &Sub, SString S, int pos, int len) {
    // 求子串
    if (pos + len - 1 > S.length)  // 子串范围越界
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

int StrLength(SString S) {
    return S.length;
}


int StrCompare(SString S, SString T) {
    // 比较操作。若S > T，则返回 > 0；若S = T，则返回0；若S < T，则返回 <0
    for (int i = 1; i <= S.length && i < T.length; i++) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) return i - T.length;
    else return 0;
}

int Index1(SString S, SString T) {
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) ++i;
        else return i;
    }
    return 0;
}

void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else j = next[j];
    }
}

int Index_KMP(SString S, SString T) {
    int i = 1, j = 1;
    int next[T.length + 1];
    get_next(T, next);
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else j = next[j];
    }
    if (j > T.length) return i - T.length;
    else return 0;
}