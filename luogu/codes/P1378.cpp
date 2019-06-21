/*************************************************************
 *  > File Name        : P1378.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/21 12:44:56
 *  > Algorithm        : [Dfs]Ex
**************************************************************/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10;

int n;
double left, right, up, down;
double px[maxn], py[maxn], r[maxn];
double dis[maxn][maxn], ans = 0;
bool vis[maxn];

void calc(int i) {
    r[i] = min( min(px[i] - left, right - px[i]), min(py[i] - down, up - py[i]) );
    for (int j = 1; j <= n; ++j) {
        if (vis[j]) {
            r[i] = min(r[i], dis[i][j] - r[j]);
        }
    }
    r[i] = max(r[i], 0.0);
}

void dfs(int now, double sum) {
    if (now == n + 1) ans = max(ans, sum);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            calc(i);
            vis[i] = 1;
            dfs(now + 1, sum + r[i] * r[i] * M_PI);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    double x, y;
    scanf("%lf %lf", &x, &y);
    left = right = x;
    up   = down  = y;
    scanf("%lf %lf", &x, &y);
    left  = min(left,  x);
    right = max(right, x);
    down  = min(down,  y);
    up    = max(up,    y);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &px[i], &py[i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            dis[i][j] = dis[j][i] = sqrt(pow(px[i] - px[j], 2) + pow(py[i] - py[j], 2));
        }
    }
    dfs(1, 0);
    printf("%.0lf\n", (up - down) * (right - left) - ans);
    return 0;
}