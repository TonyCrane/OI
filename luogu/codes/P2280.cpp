/*************************************************************
 *  > File Name        : P2280.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 16:53:12
 *  > Algorithm        : [DataStructure]PrefixSumIn2D
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5010;

int v[maxn][maxn], ans;

int main() {
    int n = read(), r = read();
    for (int i = 1; i <= n; ++i) {
        int xi = read(), yi = read(), vi = read();
        v[xi + 1][yi + 1] = vi;
    }
    for (int i = 1; i <= maxn - 10; ++i) {
        for (int j = 1; j <= maxn - 10; ++j) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= maxn - 10 - r; ++i) {
        for (int j = 0; j <= maxn - 10 - r; ++j) {
            ans = max(ans, v[i + r][j + r] - v[i + r][j] - v[i][j + r] + v[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}