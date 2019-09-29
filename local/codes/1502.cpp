/*************************************************************
 *  > File Name        : 1502.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/29 15:06:14
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

int n, m, zhu[maxn], zuo[maxn], cnt[maxn];
int G[maxn][maxn], ans1, ans2;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        zhu[i] = read();
        ans1 += zhu[i];
        cnt[zhu[i]]++;
    }
    for (int i = 1; i <= m; ++i) {
        zuo[i] = read();
        ans1 += zuo[i];
    }
    for (int i = 1; i <= m; ++i) {
        if (cnt[zuo[i]]) {
            ans1 -= zuo[i];
            cnt[zuo[i]]--;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            G[i][j] = zuo[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (G[j][i] < zhu[i]) {
                ans2 += G[j][i];
            } else {
                ans2 += zhu[i];
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}