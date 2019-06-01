/*************************************************************
 *  > File Name        : P1083.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 17:01:21
 *  > Algorithm        : [DataStructure]DiffArray
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;

int diff[maxn], pre[maxn], r[maxn], d[maxn], s[maxn], t[maxn];
int n, m;

bool check(int x) {
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= x; ++i) {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + diff[i];
        if (pre[i] > r[i]) return false;
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) r[i] = read();
    for (int i = 1; i <= m; ++i) d[i] = read(), s[i] = read(), t[i] = read();
    int l = 1, r = m;
    if (check(m)) { puts("0"); return 0; }
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    puts("-1"); printf("%d\n", l);
    return 0;
}