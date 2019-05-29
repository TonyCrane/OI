/*************************************************************
 *  > File Name        : P3374.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/29 12:16:56
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

const int maxn = 500010 * 4;

int tree[maxn], n, m;
int lowbit(int k) { return k & -k; }
void add(int x, int k) {
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
}
int sum(int x) {
    int ans = 0;
    while (x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        int a = read();
        add(i, a);
    }
    for (int i = 1; i <= m; ++i) {
        int a = read(), b = read(), c = read();
        if (a == 1) add(b, c);
        if (a == 2) printf("%d\n", sum(c) - sum(b - 1));
    }
    return 0;
}