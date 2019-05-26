/*************************************************************
 *  > File Name        : P2678.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 15:38:14
 *  > Algorithm        : 二分答案
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 50010;

int l, n, m, d[maxn];

bool check(int mid) {
    int last = 0, tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] - last < mid) tot++;
        else last = d[i];
    }
    return tot <= m;
}

int main() {
    l = read(); n = read(); m = read();
    for (int i = 1; i <= n; ++i) d[i] = read();
    d[++n] = l;
    int left = 1, right = l + 1;
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) left = mid;
        else right = mid;
    }
    printf("%d\n", left);
    return 0;
}