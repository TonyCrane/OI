/*************************************************************
 *  > File Name        : P3498.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/02 10:39:08
 *  > Algorithm        : [DataStructure]HashTable
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

const int N = 200010;
const int P = 2333333;
const int D = 1000173169;
const int M = 1048575;

int n, i, j, ans, cnt, now, tot;
int head[M], ver[M], Next[M], Pow[N], a[N], pre[N], suf[N], val[N], vis[M + 1];

inline int Hash(int l,int r) {
    return min((LL)(pre[r] - (LL)pre[l - 1] * Pow[r - l + 1] % D + D) % D, (LL)(suf[l] - (LL)suf[r + 1] * Pow[r - l + 1] % D + D) % D);
}

inline bool insert(int v) {
    int u = v & M;
    if (vis[u] < i) vis[u] = i, head[u] = 0;
    for (int s = head[u]; s; s = Next[s]) if (ver[s] == v) return false;
    Next[++tot] = head[u];
    head[u]     = tot;
    ver[tot]    = v;
    return true;
}

int main() {
    n = read(); Pow[0] = 1;
    for (i = 1; i <= n; ++i) { a[i] = read(); }
    for (i = 1; i <= n; ++i) { Pow[i] = (LL)((LL)Pow[i - 1] * P)%D; }
    for (i = 1; i <= n; ++i) { pre[i] = (LL)((LL)pre[i - 1] * P + a[i]) % D; }
    for (i = n; i >= 1; --i) { suf[i] = (LL)((LL)suf[i + 1] * P + a[i]) % D; }
    for (i = 1; i <= n; ++i) { 
        for (tot = 0, j = i; j <= n; j += i) {
            if (insert(Hash(j - i + 1, j))) val[i]++;
        }
    }
    for (i = 1; i <= n; ++i) {
        if (val[i] > ans) ans = val[i], cnt = 1;
        else if (val[i] == ans) cnt++;
    }
    printf("%d %d\n", ans, cnt);
    for (i = 1; i <= n; ++i) {
        if (val[i] == ans) {
            printf("%d ", i);
        }
    }
    return 0;
}