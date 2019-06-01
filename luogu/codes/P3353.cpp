/*************************************************************
 *  > File Name        : P3353.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 16:43:28
 *  > Algorithm        : [DataStructure]PrefixSum
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

int light[maxn], pre[maxn];
int ans = -1, maxx = 1;

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read();
        light[x] += y;
        maxx = max(maxx, x);
    }
    for (int i = 1; i <= maxx; ++i) pre[i] = pre[i - 1] + light[i];
    for (int i = 1; i <= maxx; ++i) ans = max(ans, pre[i] - pre[i - m]);
    printf("%d\n", ans);
    return 0;
}