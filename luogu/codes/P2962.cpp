/*************************************************************
 *  > File Name        : P2962.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/25 14:21:35
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * (LL)f;
}

int n, m, cnt, ans = 0x3f3f3f3f;
bool flag = false;
LL a[40], last;
map<LL, int> _map;

void dfs(int x, LL now, int dep) {
    if (x == cnt + 1) {
        if (last == now) {
            ans = min(ans, dep);
        } 
        if (!flag) {
            if (!_map[now] || _map[now] > dep) _map[now] = dep;
        } else {
		    if (!_map[last - now]) return;
		    ans = min(ans, dep + _map[last - now]);
        }
        return;
    }
    dfs(x + 1, now ^ a[x], dep + 1);
    dfs(x + 1, now, dep);
}

int main() {
    scanf("%d %d", &n, &m);
    last = (1LL << n) - 1;;
    for (int i = 1; i <= m; ++i) {
        LL x = read(), y = read();
        a[x] ^= (1LL << (y - 1));
        a[y] ^= (1LL << (x - 1));
    }
    for (int i = 1; i <= n; ++i) {
        a[i] ^= (1LL << (i - 1));
    }
    cnt = n / 2;
    dfs(1, 0LL, 0);
    flag = true; cnt = n;
    dfs(n / 2 + 1, 0LL, 0);
    printf("%d\n", ans);
    return 0;
}
