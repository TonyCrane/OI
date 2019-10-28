/*************************************************************
 *  > File Name        : c1080_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/28 16:03:26
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 60;
const LL mod  = 1e9 + 7;

LL m, a[maxn], b[maxn], c[maxn], d[maxn], l[maxn];
LL siz[maxn], ans[maxn];

map<pair<LL, LL>, LL> m1;
map<pair<LL, pair<LL, LL> >, LL> m2;

LL dist(LL id, LL pos1, LL pos2) {
    if (id == 0 || pos1 == pos2) return 0;
    pair<LL, pair<LL, LL> > q = make_pair(id, make_pair(pos1, pos2));
    if (m2.count(q)) return m2[q];
    if (pos1 < siz[a[id]]) {
        if (pos2 < siz[a[id]]) return m2[q] = dist(a[id], pos1, pos2);
        else return m2[q] = ( dist(a[id], pos1, c[id]) + dist(b[id], pos2 - siz[a[id]], d[id]) + l[id] ) % mod;
    } else {
        if (pos2 >= siz[a[id]]) return m2[q] = dist(b[id], pos1 - siz[a[id]], pos2 - siz[a[id]]);
        else return m2[q] = ( dist(a[id], pos2, c[id]) + dist(b[id], pos1 - siz[a[id]], d[id]) + l[id] ) % mod;

    }
}

LL g(LL id, LL pos) {
    if (id == 0) return 0;
    pair<LL, LL> q = pair<LL, LL>(id, pos);
    if (m1.count(q)) return m1[q];
    if (pos < siz[a[id]]) {
        return m1[q] = ( (g(a[id], pos) + g(b[id], d[id])) % mod + (dist(a[id], c[id], pos) + l[id]) * siz[b[id]] % mod ) % mod;
    } else {
        return m1[q] = ( (g(a[id], c[id]) + g(b[id], pos - siz[a[id]])) % mod + (dist(b[id], d[id], pos - siz[a[id]]) + l[id]) * siz[a[id]] % mod ) % mod;
    }
}

int main() {
    m = read(); 
    for (LL i = 1; i <= m; ++i) {
        a[i] = read(); b[i] = read(); c[i] = read(); d[i] = read(); l[i] = read();
    }
    siz[0] = 1;
    for (LL i = 1; i <= m; ++i) {
        siz[i] = (siz[a[i]] + siz[b[i]]) % mod; 
    }
    for (LL i = 1; i <= m; ++i) {
        ans[i] = (ans[a[i]] + ans[b[i]]) % mod + (siz[a[i]] * siz[b[i]]) % mod * l[i];
        ans[i] %= mod;
        ans[i] = ans[i] + siz[b[i]] * g(a[i], c[i]) % mod + siz[a[i]] * g(b[i], d[i]) % mod;
        ans[i] %= mod;
        printf("%lld\n", ans[i]);
    }
    return 0;
}