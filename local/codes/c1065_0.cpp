/*************************************************************
 *  > File Name        : c1065_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/16 12:34:36
 *  > Algorithm        : Greedy
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

struct Node {
    int l, r;
}a[maxn];

bool cmp(Node a, Node b) {
    if (a.r == b.r) return a.l > b.l;
    return a.r < b.r;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(), w = read();
        a[i].l = x - w;
        a[i].r = x + w;
    }
    sort(a + 1, a + 1 + n, cmp);
    int now = a[1].r, ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i].l >= now) {
            ans++;
            now = a[i].r;
        }
    }
    printf("%d\n", ans);
    return 0;
}