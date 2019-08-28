/*************************************************************
 *  > File Name        : c1063_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/27 12:41:49
 *  > Algorithm        : dp+queue
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;
const int inf  = 0x3f3f3f3f;

struct Tree {
    int h, w;
}t[maxn];

int n, k, d, tail = 1, head = 0;
int dp[maxn], q[maxn];

int main() {
    n = read(); k = read(); d = read();
    for (int i = 1; i <= n; ++i) {
        t[i].h = read(); t[i].w = read();
    }
    dp[1] = t[1].w; q[0] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = inf;
        while (i - q[head] > k) {
            head++;
        }
        for (int j = head; j < tail && dp[q[j]] == dp[q[head]]; ++j) {
            int ext = 0;
            if (t[q[j]].h <= t[i].h) {
                ext = d;
            }
            dp[i] = min(dp[i], dp[q[j]] + ext + t[i].w);
        }
        while (dp[i] < dp[q[tail - 1]] && head < tail) {
            tail--;
        }
        q[tail++] = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}