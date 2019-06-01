/*************************************************************
 *  > File Name        : P2709.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 16:04:56
 *  > Algorithm        : [DataStructure]CaptainMo
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

const int maxn = 50010;

struct query {
    int l, r, id, pos;
}q[maxn];

bool cmp(query a, query b) {
    if (a.pos == b.pos) {
        if (a.pos % 2 == 1) return a.r < b.r;
        else return a.r > b.r;
    }
    return a.pos < b.pos;
}

int n, m, k, len, L, R, Ans;
int ans[50010], c[50010], cnt[50010];

void del(int x) {
    Ans -= (2 * cnt[c[x]] - 1); cnt[c[x]]--;
}
void add(int x) {
    Ans += (2 * cnt[c[x]] + 1); cnt[c[x]]++;
}

int main(){
    n = read(); m = read(); k = read();
    len = sqrt(n);
    for (int i = 1; i <= n; ++i) c[i] = read();
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i; q[i].pos = q[i].l / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); L = 1;
    for (int i = 1; i <= m; ++i) {
        while (L < q[i].l) del(L++);
        while (R > q[i].r) del(R--);
        while (L > q[i].l) add(--L);
        while (R < q[i].r) add(++R);
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}