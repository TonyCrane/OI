/*************************************************************
 *  > File Name        : P6186.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/24 22:08:27
 *  > Algorithm        : BIT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0; long long f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const long long maxn = 200010;

long long n, m;
long long a[maxn], t1[maxn], t2[maxn];
long long rev[maxn];

void add(long long* t, long long x, long long k) {
    if (x == 0) return;
    for (; x <= n; x += x & -x) t[x] += k;
}
long long ask(long long* t, long long x) {
    long long res = 0;
    for (; x; x -= x & -x) res += t[x];
    return res;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        rev[i] = i - 1 - ask(t1, a[i]);
        add(t1, a[i], 1);
    }
    memset(t1, 0, sizeof(t1));
    for (int i = 1; i <= n; ++i) {
        add(t1, rev[i], 1); add(t2, rev[i], rev[i]);
    }
    for (int _ = 1; _ <= m; ++_) {
        int opt = read();
        if (opt == 1) {
            long long x = read();
            add(t1, rev[x], -1); add(t2, rev[x], -rev[x]);
            add(t1, rev[x + 1], -1); add(t2, rev[x + 1], -rev[x + 1]);
            if (a[x] > a[x + 1]) {
                long long tmp = rev[x];
                rev[x] = rev[x + 1] - 1;
                rev[x + 1] = tmp;
            } else {
                long long tmp = rev[x];
                rev[x] = rev[x + 1];
                rev[x + 1] = tmp + 1;
            }
            swap(a[x], a[x + 1]);
            add(t1, rev[x], 1); add(t2, rev[x], rev[x]);
            add(t1, rev[x + 1], 1); add(t2, rev[x + 1], rev[x + 1]);
        } else {
            long long k = read();
            if (k >= n) {
                printf("0\n");
                continue;
            }
            long long res1 = ask(t1, n) - ask(t1, k);
            long long res2 = ask(t2, n) - ask(t2, k);
            printf("%lld\n", res2 - k * res1);
        }
    }
    return 0;
}