/*************************************************************
 *  > File Name        : P1268.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/28 14:52:05
 *  > Algorithm        : Graph
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 35;
const int inf  = 0x3f3f3f3f;

int n, ans, G[maxn][maxn];

int main() {
    while (~scanf("%d", &n)) {
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                G[i][j] = G[j][i] = read();
            }
        }
        ans = G[1][2];
        for (int i = 3; i <= n; ++i) {
            int dt = inf;
            for (int j = 2; j < i; ++j) {
                dt = min(dt, (G[1][i] - G[1][j] + G[j][i]) / 2);
            }
            ans += dt;
        }
        printf("%d\n", ans);
    }
    return 0;
}