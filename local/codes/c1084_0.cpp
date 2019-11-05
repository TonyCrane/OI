/*************************************************************
 *  > File Name        : c1084_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/05 12:19:59
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

char n[12], _n[12], __n[12];
int k, cnt, ans1, ans2, len;

void dfs1(int now, int times) {
    if (now >= len || times >= k) {
        int res = 0;
        for (int i = 0; i < len; ++i) res = res * 10 + _n[i];
        ans1 = max(ans1, res);
        return;
    }
    for (int i = now + 1; i < len; ++i) {
        if (_n[i] >= _n[now]) {
            swap(_n[i], _n[now]);
            dfs1(now + 1, times + 1);
            swap(_n[i], _n[now]);
        }
    }
    dfs1(now + 1, times);
}

void dfs2(int now, int times) {
    if (now >= len || times >= k) {
        int res = 0;
        for (int i = 0; i < len; ++i) res = res * 10 + __n[i];
        ans2 = min(ans2, res);
        return;
    }
    for (int i = now + 1; i < len; ++i) {
        if (__n[i] <= __n[now]) {
            if (now == 0 && __n[i] == 0) continue;
            swap(__n[i], __n[now]);
            dfs2(now + 1, times + 1);
            swap(__n[i], __n[now]);
        }
    }
    dfs2(now + 1, times);
}

int main() {
    int T = read();
    while (T--) {
        scanf("%s %d", n, &k); int k1 = k, k2 = k;
        len = strlen(n);
        for (int i = 0; i < len; ++i) n[i] -= '0';
        memcpy( _n, n, sizeof(n));
        memcpy(__n, n, sizeof(n));
        ans1 = 0; ans2 = 0x3f3f3f3f;
        dfs1(0, 0);
        dfs2(0, 0);
        printf("%d\n", ans1 - ans2);
    }
    return 0;
}