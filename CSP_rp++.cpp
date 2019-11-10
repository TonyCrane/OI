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



/*-------- 存储及逻辑 --------*/ 
int       --> 2 ^ 31 - 1 --> 2e9  --> 4 bytes
long long --> 2 ^ 63 - 1 --> 9e18 --> 8 bytes
char      --> 2 ^ 7 - 1  --> 127  --> 1 byte

INT_MAX = 0x7fffffff
half_INT_MAX = 0x3f3f3f3f
LONGLONG_MAX = 0x7fffffffffffffff
memset(a, 0, sizeof(a));     0
memset(a, -1, sizeof(a));    -1
memset(a, 0x7f, sizeof(a));  inf
memset(a, 0x3f, sizeof(a));  inf / 2
memset(a, 0x80, sizeof(a));  -inf
memset(a, 0xc0, sizeof(a));  -inf / 2
memset(a, 0x43, sizeof(a));  double inf
memset(a, 0xfe, sizeof(a));  double -inf

1 << n  -->  2^n
n << 1  -->  2n
n >> 1  -->  n / 2 向下取整  //普通 n/2 向0取整

(n >> k) & 1        n在二进制下k位
n & ((1 << k) - 1)  n在二进制下后k位
n xor (1 << k)      n在二进制下k位取反
n | (1 << k)        n在二进制下k位赋值1
n & (~(1 << k))     n在二进制下k位赋值0

(n ^ 1) ^ 1 = n
n --> odd   n xor 1 = n - 1
n --> even  n xor 1 = n + 1

lowbit(x) = x & (~x + 1) = x & -x

/*-------- STL常用 --------*/
