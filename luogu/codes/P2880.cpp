/*************************************************************
 *  > File Name        : P2880.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/26 13:01:37
 *  > Algorithm        : [DataStructure]BIT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 50010;
const int inf  = 0x3f3f3f3f;

int n, q, a[maxn], maxx[maxn], minn[maxn];

void add(int x, int k) {
    for(; x <= n; x += x & -x) maxx[x] = max(maxx[x], k), minn[x] = min(minn[x], k);
}

int query(int l, int r) {
    int minnn = inf, maxxx = -1;
    while (l <= r) {
        for (; r - (r & -r) >= l; r -= r & -r) maxxx = max(maxxx, maxx[r]), minnn = min(minnn, minn[r]);
        maxxx = max(a[r], maxxx);
        minnn = min(a[r], minnn);
        r--;
    }
    return maxxx-minnn;
}

int main() {
    n = read(); q = read();
    memset(minn, 0x3f, sizeof(minn));
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        add(i, a[i]);
    }
    for (int i = 1; i <= q; ++i) {
        int l = read(), r = read();
        printf("%d\n", query(l, r));
    }
    return 0;
}