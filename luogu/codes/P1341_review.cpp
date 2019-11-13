/*************************************************************
 *  > File Name        : P1341_review.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/13 06:51:21
 *  > Algorithm        : review EulerPath
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500;

int n, G[maxn][maxn], ansi, deg[maxn];
char str[maxn], ans[maxn * maxn];

void dfs(int x) {
    for (int y = 1; y <= maxn; ++y) {
        if (G[x][y]) {
            G[x][y] = 0;
            G[y][x] = 0;
            dfs(y);
        }
    }
    ans[++ansi] = x;
    return;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", str);
        G[str[0]][str[1]] = 1;
        G[str[1]][str[0]] = 1;
        deg[str[0]]++;
        deg[str[1]]++;
    }
    int cnt = 0, root = 0;
    for (int i = 1; i <= maxn; ++i) {
        if (deg[i] % 2) {
            cnt++;
            if (!root) root = i;
        }
    }
    if (!root) {
        for (int i = 1; i <= maxn; ++i) {
            if (deg[i]) {
                root = i; break;
            }
        }
    }
    if (cnt && cnt != 2) {
        printf("No Solution\n");
        return 0;
    }
    dfs(root);
    for (int i = ansi; i >= 1; --i) {
        printf("%c", ans[i]);
    }
    puts("");
    return 0;
}