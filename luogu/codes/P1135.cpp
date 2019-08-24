/*************************************************************
 *  > File Name        : P1135.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/24 15:48:18
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 210;

int n, a, b;
int k[maxn], dis[maxn];

void dfs(int now, int sum) {
    if (now <= 0 || now > n || sum > dis[now]) return;
    dis[now] = sum;
    dfs(now + k[now], sum + 1);
    dfs(now - k[now], sum + 1);
}

int main() {
    n = read(); a = read(); b = read();
    for (int i = 1; i <= n; ++i) {
        k[i] = read();
    }
    memset(dis, 0x3f, sizeof(dis));
    dfs(a, 0);
    printf(dis[b] == 0x3f3f3f3f ? "-1" : "%d\n", dis[b]);
    return 0;
}