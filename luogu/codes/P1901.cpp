/*************************************************************
 *  > File Name        : P1901.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/17 16:38:31
 *  > Algorithm        : stack
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

int s[maxn], h[maxn], v[maxn], sum[maxn];
int n, top, ans;

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        h[i] = read(); v[i] = read();
        while (top >= 1 && h[s[top]] < h[i]) {
            sum[i] += v[s[top--]];
        }
        sum[s[top]] += v[i];
        s[++top] = i;
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, sum[i]);
    }
    printf("%d\n", ans);
    return 0;
}