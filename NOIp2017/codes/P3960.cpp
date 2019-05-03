/*************************************************************
 *  > File Name        : P3960.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/03 16:25:01
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
const int maxn = 300010;

struct Node {
    int x, y;
} a[maxn];
int n, m, q, tot;
LL last[maxn], h[maxn], pos[510][50010], ans;

int main() {
    n = read(); m = read(); q = read();
    for (int i = 1; i <= q; ++i) {
        a[i].x = read();
        a[i].y = read();
        h[i] = a[i].x;
    }
    for (int i = 1; i <= n; ++i) {
        last[i] = last[i - 1] + m;
    }
    sort(h + 1, h + q + 1);                 //排序
    tot = unique(h + 1, h + q + 1) - h - 1; //去重
    LL t;
    for (int i = 1; i <= tot; ++i) { //编号
        t = (LL)(h[i] - 1) * m;
        for (int j = 1; j <= m; ++j) {
            pos[i][j] = ++t;
        }
    }
    int where; //a[i].x在h数组中的位置
    for (int i = 1; i <= q; ++i) { //模拟
        for (int j = 1; j <= tot; ++j) {
            if (h[j] == a[i].x) {
                where = j;
                break;
            }
        }
        if (a[i].y == m) { //在最后一列
            ans = last[h[where]];
        } else {
            ans = pos[where][a[i].y];
        }
        printf("%lld\n", ans);
        if (a[i].y != m) { //向左看齐
            for (int j = a[i].y; j < m - 1; ++j) {
                pos[where][j] = pos[where][j + 1];
            }
            pos[where][m - 1] = last[h[where]];
        }
        for (int j = h[where]; j < n; ++j) { //向前看齐
            last[j] = last[j + 1];
        }
        last[n] = ans;
    }
    return 0;
}

/* 50分 */