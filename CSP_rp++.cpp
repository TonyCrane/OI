/*************************************************************
 *  > Description      : 复赛相关模板
 *  > File Name        : CSP_rp++.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/10 20:59:43
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

/* 读入优化 */
inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}