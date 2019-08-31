/*************************************************************
 *  > File Name        : P1156.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/30 15:23:55
 *  > Algorithm        : dp
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

struct Node {
    int t, f, h;
}a[maxn];
bool cmp(Node a, Node b) {
    return a.t < b.t;
}

int d, g, dp[maxn];

int main() {
    d = read(); g = read();
    for (int i = 1; i <= g; ++i) {
        a[i].t = read();
        a[i].f = read();
        a[i].h = read();
    }
    sort(a + 1, a + 1 + g, cmp);
    dp[0] = 10;
    for (int i = 1; i <= g; ++i) {
        for (int j = d; j >= 0; --j) {
            if (dp[j] < a[i].t) continue;
            if (j + a[i].h >= d) {
                printf("%d\n", a[i].t);
                return 0;
            }
            dp[j + a[i].h] = max(dp[j + a[i].h], dp[j]);
            dp[j] += a[i].f;
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}