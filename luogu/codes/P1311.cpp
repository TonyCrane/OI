/*************************************************************
 *  > File Name        : P1311.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 19:31:08
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

const int maxn = 200010;

int n, k, p, las[maxn], sum[maxn], vis[maxn];

int main() {
    n = read(); k = read(); p = read();
    int now = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        int col = read(), pri = read();
        if (pri <= p) {
            now = i;
        }
        if (now >= las[col]) {
            sum[col] = vis[col];
        }
        las[col] = i; vis[col]++;
        ans += sum[col];
    }
    printf("%d\n", ans);
    return 0;
}