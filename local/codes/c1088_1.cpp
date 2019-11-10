/*************************************************************
 *  > File Name        : c1088_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/10 12:56:59
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

const LL prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
LL n, ans, maxx;

void dfs(LL cnt, LL now, LL dep) {
    if (dep >= 11) return; 
    if (cnt > maxx) {
        ans = now;
        maxx = cnt;
    }
    if (cnt == maxx && ans > now) {
        ans = now;
    }
    for (LL i = 1; i <= 64; ++i) {
        if (now * prime[dep] > n) break;
        now *= prime[dep];
        dfs(cnt * (i + 1), now, dep + 1);
    }
}

int main() {
    n = read();
    dfs(1, 1, 1);
    printf("%lld\n", ans);
    return 0;
}