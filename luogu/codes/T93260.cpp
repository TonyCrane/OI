/*************************************************************
 *  > File Name        : T93260.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 11:42:35
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
typedef long long LL;

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)? EOF : *p1++;
}
inline int read() {
    int x = 0; int f = 1; char ch = nc();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = nc();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = nc();}
    return x * f;
}

const LL maxn = 10010;

LL n, ans;
bool vis[maxn];

struct Node {
    LL health, energy, attack, defense, collapse;
}a[maxn];

bool cmp(LL x, LL y) {
    return a[x].health >= a[y].health && a[x].energy >= a[y].energy && \
           a[x].attack >= a[y].attack && a[x].defense >= a[y].defense;
}

void dfs(LL now, LL last, LL sum) {
    if (sum > ans) ans = sum;
    if (!cmp(now, last)) return;
    sum += a[now].collapse; vis[now] = true;
    for (LL i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, now, sum);
        }
    }
}

int main() {
    n = read();
    for (LL i = 1; i <= n; ++i) {
        a[i].health = read();
        a[i].energy = read();
        a[i].attack = read();
        a[i].defense = read();
        a[i].collapse = read();
    }
    a[0].health = -0x3f3f3f3f;
    a[0].energy = -0x3f3f3f3f;
    a[0].attack = -0x3f3f3f3f;
    a[0].defense = -0x3f3f3f3f;
    a[0].collapse = -0x3f3f3f3f;
    for (LL i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        dfs(i, 0, 0);
    }
    printf("%lld\n", ans);
    return 0;
}