/*************************************************************
 *  > File Name        : P5665.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/26 12:40:50
 *  > Algorithm        : partition
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

const int maxn = 40000010;
const int maxm = 100010;
const int mod  = 1 << 30;

int n, type, x, y, z, m, b[maxn], p[maxm], l[maxm], r[maxm], g[maxn];
int q[maxn], head, tail;
LL sum[maxn];
__int128 ans = 0;

void print(__int128 x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    n = read(); type = read();
    if (type == 0) {
        for (int i = 1; i <= n; ++i) {
            sum[i] = read();
            sum[i] += sum[i - 1];
        }
    } else {
        x = read(); y = read(); z = read(); b[1] = read(); b[2] = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            p[i] = read(); l[i] = read(); r[i] = read();
        }
        for (int i = 3; i <= n; ++i) b[i] = (1LL * x * b[i - 1] + 1LL * y * b[i - 2] + z) % mod;
        for (int i = 1, j = 1; i <= n; ++i) {
            while (p[j] < i) j++;
            sum[i] = (b[i] % (r[j] - l[j] + 1)) + l[j];
            sum[i] += sum[i - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        while (head < tail && sum[i] - sum[q[head + 1]] >= sum[q[head + 1]] - sum[g[q[head + 1]]]) head++;
        g[i] = q[head];
        while (head < tail && (__int128)2 * sum[q[tail]] - sum[g[q[tail]]] >= (__int128)2 * sum[i] - sum[g[i]]) tail--;
        q[++tail] = i;
    }
    int now = n;
    while (now) {
        ans = ans + (__int128)(sum[now] - sum[g[now]]) * (sum[now] - sum[g[now]]);
        now = g[now];
    }
    print(ans);
    puts("");
    return 0;
}