/*************************************************************
 *  > File Name        : P3373_BIT.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/29 12:37:53
 *  > Algorithm        : [DataStructure]BIT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

long long n, m, tree[maxn], tree1[maxn];

void add(long long *t, long long x, long long num) {
    while (x <= n) {
        t[x] += num;
        x += x & -x;
    }
}

long long sum(long long *t, long long x) {
    long long ans = 0;
    while (x > 0) {
        ans += t[x];
        x -= x & -x;
    }
    return ans;
}

int main() {
    n = read(); m = read();
    long long a, b = 0;
    for (long long i = 1; i <= n; ++i) {
        a = read(); b = a - b;
        add(tree , i, b);
        add(tree1, i, (i - 1) * b);
        b = a;
    }
    for (long long i = 1; i <= m; ++i) {
        int t = read(), x, y, z;
        if (t == 1) {
            x = read(); y = read(); z = read();
            add(tree, x, z);
            add(tree, y + 1, -z);
            add(tree1, x, z * (x - 1));
            add(tree1, y + 1, -z * y);
        } else {
            x = read(); y = read();
            printf("%lld\n", (y * sum(tree, y) - (x - 1) * sum(tree, x - 1)) - (sum(tree1, y) - sum(tree1, x - 1)));
        }
    }
    return 0;
}