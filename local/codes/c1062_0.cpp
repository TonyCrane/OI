/*************************************************************
 *  > File Name        : c1062_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/19 12:27:00
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, s, p, ans;

void dfs(int last, int now, int num) {
    if (num == n && now == s) { ans++; return; }
    if (num >= n) return;
    for (int i = -p; i <= p; ++i) {
        int nxt = last + i;
        if (nxt <= 0) continue;
        if (now + nxt > s) continue;
        dfs(nxt, now + nxt, num + 1);
    }
}

int main() {
    n = read(); s = read(); p = read();
    for (int i = 1; i < s; ++i) {
        dfs(i, i, 1);
    }
    printf("%d\n", ans);
    return 0;
}