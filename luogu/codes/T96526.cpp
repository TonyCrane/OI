/*************************************************************
 *  > File Name        : T96526.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 09:15:17
 *  > Algorithm        : DS
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

const LL maxn = 100010;
const LL mod  = 19260817;

LL mul_mod(LL a, LL b, LL n){
    LL res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}
LL pow_mod(LL a, LL p, LL n){
    LL res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
}

vector<LL> G[maxn];
LL w[maxn], n, m, ans;

bool vis[maxn]; LL dep[maxn], siz[maxn];
void dfs1(LL x) {
    vis[x] = true; siz[x] = 1;
    for (LL i = 0; i < G[x].size(); ++i) {
        LL& v = G[x][i];
        if (vis[v]) continue;
        dep[v] = dep[x] + 1;
        dfs1(v);
        siz[x] += siz[v];
    }
}

vector<LL> val;
void dfs(LL x) {
    val.push_back(w[x]);
    for (LL i = 0; i < G[x].size(); ++i) {
        LL&v = G[x][i];
        if (dep[v] < dep[x]) continue;
        dfs(v);
    }
}

int main() {
    n = read(); m = read();
    for (LL i = 1; i <= n; ++i) w[i] = read();
    for (LL i = 1; i <  n; ++i) {
        LL u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1);
    for (LL i = 1; i <= m; ++i) {
        LL x = read(); val.clear();
        dfs(x);
        LL a = 1, b = pow_mod(2, siz[x] * (mod - 2), mod);
        for (LL i = 0; i < val.size(); ++i) {
            a *= val[i] + 1; a %= mod;
        }
        a--;
        ans += mul_mod(a, b, mod);
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}