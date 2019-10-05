/*************************************************************
 *  > File Name        : c1071_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/04 12:07:48
 *  > Algorithm        : math
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

int n, m, in[maxn][maxn];
int limf[maxn], liml[maxn], match[maxn], vis[maxn], cnt;
bool judge[maxn][maxn];
long long ans;

bool dfs(int x) {
    for (int i = 1; i <= m; ++i) {
        if (vis[i] != cnt && judge[x][i]) {
            vis[i] = cnt;
            if (!match[i] || dfs(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            in[i][j] = read();
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            limf[j] = max(limf[j], in[i][j]);
            liml[i] = max(liml[i], in[i][j]);
            ans += (long long)in[i][j];
            if (in[i][j]) ans--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (in[i][j] && limf[j] == liml[i]) {
                judge[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cnt++;
        dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (liml[i]) ans -= liml[i] - 1;
    }
    for (int i = 1; i <= m; ++i) {
        if (!match[i] && limf[i]) ans -= limf[i] - 1;
    }
    printf("%lld\n", ans);
    return 0;
}