/*************************************************************
 *  > File Name        : P2668.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/06 16:00:14
 *  > Algorithm        : [Greedy]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, ans, hav;
int p[15];

void func(int now) {
    if (now > ans) return;
    if (hav == n) ans = now;
    for (int i = 3; i <= 14; ++i) {
        if (p[i] >= 3) {
            int nxt = 0;
            while (i + nxt <= 14 && p[i + nxt] >= 3) {
                nxt++;
                if (nxt >= 2) {
                    for (int j = i; j <= i + nxt - 1; ++j) p[j] -= 3;
                    hav += 3 * nxt; func(now + 1);
                    for (int j = 1; j <= i + nxt - 1; ++j) p[j] += 3;
                    hav -= 3 * nxt;
                    if (now >= ans) return;
                }
            }
        }
    }
    for (int i = 3; i <= 14; ++i) {
        if (p[i] >= 2) {
            int nxt = 0;
            while (i + nxt <= 14 && p[i + nxt] >= 2) {
                nxt++;
                if (nxt >= 3) {
                    for (int j = i; j <= i + nxt - 1; ++j) p[j] -= 2;
                    hav += 2 * nxt; func(now + 1);
                    for (int j = 1; j <= i + nxt - 1; ++j) p[j] += 2;
                    hav -= 2 * nxt;
                    if (now >= ans) return;
                }
            }
        }
    }
    for (int i = 3; i <= 14; ++i) {
        if (p[i] >= 1) {
            int nxt = 0;
            while (i + nxt <= 14 && p[i + nxt] >= 1) {
                nxt++;
                if (nxt >= 5) {
                    for (int j = i; j <= i + nxt - 1; ++j) p[j] -= 1;
                    hav += 1 * nxt; func(now + 1);
                    for (int j = 1; j <= i + nxt - 1; ++j) p[j] += 1;
                    hav -= 1 * nxt;
                    if (now >= ans) return;
                }
            }
        }
    }
    int si = 0, san = 0, dui = 0, dan = 0;
    for (int i = 0; i <= 14; ++i) {
        if      (p[i] == 4) si++,now++;
        else if (p[i] == 3) san++,now++;
        else if (p[i] == 2) dui++;
        else if (p[i] == 1) dan++;
        if (now > ans) return;
    }
    while (si > 0) {
        if      (dui >= 2) dui -= 2, si--;
        else if (dan >= 2) dan -= 2, si--;
        else if (dui == 1) dui -= 1, si--;
        else si--;
    }
    while (san > 0) {
        if      (dui > 0) dui--, san--;
        else if (dan > 0) dan--, san--;
        else san--;
    }
    now = now + dan + dui;
    ans = min(ans, now);
}

int main() {
    int T = read(); n = read();
    while (T--) {
        ans = inf;
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; ++i) {
            int x = read(), y = read();
            p[x]++;
        }
        p[14] = p[1]; p[1] = 0;
        func(0);
        printf("%d\n", ans);
    }
    return 0;
}