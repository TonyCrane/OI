/*************************************************************
 *  > File Name        : c1073_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/10 12:52:29
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

const int maxn = 500010;

int n, r, c, p[maxn];

bool check(int x) {
    int cnt = 0, tmp = 0;
    while (tmp + 1 <= n - c + 1) {
        tmp++;
        if (p[tmp + c - 1] - p[tmp] <= x) {
            tmp += c - 1;
            cnt++;
        }
    }
    if (cnt >= r) return true;
    return false;
}

int main() {
    n = read(); r = read(); c = read();
    for (int i = 1; i <= n; ++i) {
        p[i] = read();
    }
    sort(p + 1, p + 1 + n);
    int le = 0, ri = p[n] - p[1], mid;
    while (le + 1 < ri) {
        mid = (le + ri) / 2;
        if (check(mid)) ri = mid;
        else le = mid;
    }
    if (check(le)) printf("%d\n", le);
    else printf("%d\n", ri);
    return 0;
}