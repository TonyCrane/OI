/*************************************************************
 *  > File Name        : c1085_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/07 12:35:37
 *  > Algorithm        : DP
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
    double v, w;
}stone[maxn], water[maxn];
bool cmp(Node a, Node b) {
    return a.w / a.v > b.w / b.v;
}

int n, w, sum1, sum2;
double dp[50010], ans;

int main() {
    n = read(); w = read();
    for (int i = 1; i <= n; ++i) {
        int a = read(), b = read(), t = read();
        if (t) { sum2++;
            water[sum2].v = a;
            water[sum2].w = b;
        } else { sum1++;
            stone[sum1].v = a;
            stone[sum1].w = b;
        }
    }
    sort(water + 1, water + 1 + sum2, cmp);
    for (int i = 1; i <= sum1; ++i) {
        for (int j = w; j >= stone[i].v; --j) {
            dp[j] = max(dp[j], dp[j - (int)stone[i].v] + stone[i].w);
        }
    }
    for (int i = w; i >= 0; --i) {
        int cnt = 1; double nowans = 0, now = w - i;
        while (now >= water[cnt].v && cnt <= sum2) {
            nowans += water[cnt].w;
            now    -= water[cnt].v;
            cnt++;
        }
        if (cnt <= sum2) {
            nowans += (water[cnt].w / water[cnt].v) * now;
        }
        ans = max(ans, nowans + dp[i]);
    }
    printf("%.2lf\n", ans);
    return 0;
}