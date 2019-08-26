/*************************************************************
 *  > File Name        : P2897.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/26 12:40:43
 *  > Algorithm        : [DataStructure]stack
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
inline LL readll() {
    LL x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;
const int inf  = 0x3f3f3f3f;

struct Node {
    LL w;
    int h, id;
} p[maxn];

int n, minp = inf, minid;
LL ans[maxn], now;

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        int w = readll(), h = read();
        p[i] = (Node){w, h, i};
        if (minp > h) {
            minp = h;
            minid = i;
        }
    }
    p[0].h = p[n + 1].h = inf;
    Node s[maxn]; int top = 0;
    s[++top] = p[minid]; s[0].h = inf;
    int l = minid, r = minid, id;
    for (int i = 1; i <= n; ++i) {
        int res = 0;
        if (p[l - 1].h < p[r + 1].h) id = --l;
        else id = ++r;
        while (p[id].h > s[top].h && top) {
            s[top].w += res;
            ans[s[top].id] = now + s[top].w;
            now += s[top].w * (min(p[id].h, s[top - 1].h) - s[top].h);
            res = s[top--].w;
        }
        p[id].w += res;
        s[++top] = p[id];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}