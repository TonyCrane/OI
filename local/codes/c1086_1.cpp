/*************************************************************
 *  > File Name        : c1086_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/07 15:14:59
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

const int maxn = 1010;

struct Node {
    int a, b, c;
}p[maxn];
bool cmp(Node a, Node b) {
    return b.b * a.c < a.b * b.c;
}

int n, t, ans, dp[maxn * 3];

int main() {
    int T = read();
    while (T--) {
        n = read(); t = read();
        for (int i = 1; i <= n; ++i) {
            p[i].a = read();
            p[i].b = read();
            p[i].c = read();
        }
        sort(p + 1, p + 1 + n, cmp);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = t; j >= p[i].c; --j) {
                dp[j] = max(dp[j], dp[j - p[i].c] + p[i].a - p[i].b * j);
            }
        }
        ans = 0;
        for (int i = 1; i <= t; ++i) {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}