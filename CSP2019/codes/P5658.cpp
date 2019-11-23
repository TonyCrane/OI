/*************************************************************
 *  > File Name        : P5658.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/23 12:24:44
 *  > Algorithm        : brackets
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

const LL maxn = 500010;

LL n, ans[maxn], fa[maxn], last[maxn], Ans;
char ch[maxn];
vector<LL> G[maxn];

void dfs(LL u) {
    last[u] = last[fa[u]];
    if (ch[u] == '(') {
        last[u] = u;
    } else if (last[u] != 0) {
        ans[u] = ans[fa[last[u]]] + 1;
        last[u] = last[fa[last[u]]];
    }
    for (LL i = 0; i < G[u].size(); ++i) {
        dfs(G[u][i]);
    }
}

int main() {
    n = read();
    scanf("%s", ch + 1);
    for (LL i = 2; i <= n; ++i) {
        fa[i] = read();
        G[fa[i]].push_back(i);
    }
    dfs(1); Ans ^= ans[1];
    for (LL i = 2; i <= n; ++i) {
        ans[i] += ans[fa[i]];
        Ans ^= (i * ans[i]);
    }
    printf("%lld\n", Ans);
    return 0;
}