/*************************************************************
 *  > File Name        : P2320.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/14 20:37:54
 *  > Algorithm        : 二分
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

int a[maxn], m, h;

int main() {
    m = read();
    while (m) {
        a[++h] = (m + 1) / 2;
        m /= 2;
    }
    printf("%d\n", h);
    for (int i = h; i >= 1; --i) {
        printf("%d ", a[i]);
    }
    return 0;
}