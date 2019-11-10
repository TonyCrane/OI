/*************************************************************
 *  > File Name        : c1086_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/07 15:32:56
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 30010;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int x[N], y[N], c[N], in[N][2];
long long a[N*4][4], add[N*4][4];
int n, _x1, _x2, _y1, _y2, flag;

#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt, l, mid
#define rson rt, mid+1, r

void pushdown(int o, int t) {
    a[lt][t] += add[o][t];
    a[rt][t] += add[o][t];
    add[lt][t] += add[o][t];
    add[rt][t] += add[o][t];
    add[o][t] = 0;
}

void change(int o, int l, int r, int x, long long d, int t) {
    if(l == r && l == x) {
        a[o][t] = d;
        add[o][t] = 0;
        return;
    }
    if(add[o][t]) pushdown(o, t);
    if(x <= mid) change(lson, x, d, t);
    else change(rson, x, d, t);
    a[o][t] = max(a[lt][t], a[rt][t]);
}

void update(int o, int l, int r, int L, int R, long long d, int t) {
    if(L <= l && r <= R) {
        add[o][t] += d;
        a[o][t] += d;
        return;
    }
    if(add[o][t]) pushdown(o, t);
    if(L <= mid) update(lson, L, R, d, t);
    if(R > mid) update(rson, L, R, d, t);
    a[o][t] = max(a[lt][t], a[rt][t]);
}

void Add(int x, int k) { for(; x <= n; x += x & -x) c[x] += k; }
int ask(int x) { int ans = 0; for(; x; x -= x & -x) ans += c[x]; return ans; }

void dfs(int o, int l, int r, int t) {
    if(l == r) {
        if(t == 0) {
            if(in[l][1]) Add(l, 1);
            in[l][0] = 1;
            a[o][2] = 0;
            change(1, 1, n, l, a[o][t], 2);
        }
        else if(t == 1) {
            if(in[l][0]) Add(l, 1);
            in[l][1] = 1;
            a[o][3] = 0;
            change(1, 1, n, l, a[o][t], 3);
        } else if(t == 2) {
            if(in[l][0] && in[l][1]) Add(l, -1);
            in[l][0] = 0;
        } else {
            if(in[l][0] && in[l][1]) Add(l, -1);
            in[l][1] = 0;
        }
        a[o][t] = -inf;
        return;
    }
    int lim;
    if(t == 0) lim = _x1;
    else if(t == 1) lim = _y1;
    else if(t == 2) lim = _x2+1;
    else lim = _y2+1;
    if(a[o][t] >= lim) {
        if(add[o][t]) pushdown(o, t);
        if(a[lt][t] >= lim) dfs(lson, t);
        if(a[rt][t] >= lim) dfs(rson, t);
        a[o][t] = max(a[lt][t], a[rt][t]);
    }
}

int main() {
    int T = read();
    while(T--) {
        n = read(), _x1 = read(), _y1 = read(), _x2 = read(), _y2 = read();
        memset(c, 0, sizeof(c));
        memset(add, 0, sizeof(add));
        memset(in, 0, sizeof(in));
        flag = 0;
        for(int t = 0; t < 4; t++)
            for(int i = 1; i <= n* 4 - 1; i++)
                a[i][t] = -inf;
        for(int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
        for(int i = 1; i <= n; i++) {
            if(x[i] < _x1) {
                change(1, 1, n, i, x[i], 0);
            }
            else if(x[i] <= _x2) {
                in[i][0] = 1;
                change(1, 1, n, i, x[i], 2);
                if(in[i][1])Add(i, 1);
            }
            if(y[i] < _y1) {
                change(1, 1, n, i, y[i], 1);
            }
            else if(y[i] <= _y2) {
                in[i][1] = 1;
                change(1, 1, n, i, y[i], 3);
                if(in[i][0])Add(i, 1);
            }
        }
        flag = 1;
        int m = read();
        while(m--) {
            int opt = read(), l = read(), r = read();
            if(opt == 1) {
                int d = read();
                update(1, 1, n, l, r, d, 0);
                update(1, 1, n, l, r, d, 2);
                dfs(1, 1, n, 0);
                dfs(1, 1, n, 2);
            } else if(opt == 2) {
                int d = read();
                update(1, 1, n, l, r, d, 1);
                update(1, 1, n, l, r, d, 3);
                dfs(1, 1, n, 1);
                dfs(1, 1, n, 3);
            } else {
                printf("%d\n", ask(r) - ask(l-1));
            }
        }
    }
    return 0;
}