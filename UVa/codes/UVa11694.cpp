/*************************************************************
 *  > File Name        : UVa11694.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/20 12:39:01
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

inline int readmap() {
    char ch = getchar();
    while (!(ch == '.' || (ch >= '0' && ch <= '4'))) ch = getchar();
    if (ch == '.') return -1;
    else return ch - '0';
}

const int maxn = 10;

bool fini;
int n, in[maxn][maxn], cur[maxn][maxn];
int G[maxn][maxn], ans[maxn][maxn]; // 1 / 2 "\"
int lim[maxn][maxn];
int go[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int ufs[maxn * maxn];
int find(int x) {
    if (!ufs[x]) return x;
    return find(ufs[x]);
}

bool check(int x, int y) {
    if (in[x][y] == -1) return true;
    if (cur[x][y] <= in[x][y] && cur[x][y] + lim[x][y] >= in[x][y]) return true;
    return false;
}

void dfs(int x, int y) {
    if (y == n) y = 1, x++;
    if (x == n) { fini = true; return; }
    cur[x][y]++; cur[x + 1][y + 1]++;
    lim[x][y]--; lim[x + 1][y]--; lim[x][y + 1]--; lim[x + 1][y + 1]--;
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
        if (!check(x + go[i][0], y + go[i][1])) {
            ok = false;
            break;
        }
    }
    if (ok) {
        int f1 = find(x * n - n + y), f2 = find(x * n + y + 1);
        if (f1 != f2) {
            ans[x][y] = 2;
            ufs[f1] = f2;
            dfs(x, y + 1);
            if (fini) return;
            ufs[f1] = 0;
        }
    }
    cur[x][y]--; cur[x + 1][y + 1]--;
    
    cur[x + 1][y]++; cur[x][y + 1]++; ok = true;
    for (int i = 0; i < 4; ++i) {
        if (!check(x + go[i][0], y + go[i][1])) {
            ok = false;
            break;
        }
    }
    if (ok) {
        int f1 = find(x * n + y), f2 = find(x * n - n + y + 1);
        if (f1 != f2) {
            ans[x][y] = 1;
            ufs[f1] = f2;
            dfs(x, y + 1);
            if (fini) return;
            ufs[f1] = 0;
        }
    }
    cur[x + 1][y]--; cur[x][y + 1]--;
    lim[x][y]++; lim[x + 1][y]++; lim[x][y + 1]++; lim[x + 1][y + 1]++;
}

int main() {
    int T = read();
    while (T--) {
        n = read(); n++;
        fini = false;
        memset(cur, 0, sizeof(cur));
        memset(ufs, 0, sizeof(ufs));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                lim[i][j] = 4;
                in[i][j] = readmap();
                if ((i == 1 || i == n) && (j == 1 || j == n)) { lim[i][j] = 1; continue; }
                if (i == 1 || i == n || j == 1 || j == n) lim[i][j] = 2;
            }
        }
        dfs(1, 1);
        for (int i = 1; i <= n - 1; ++i) {
            for (int j = 1; j <= n - 1; ++j) {
                if (ans[i][j] == 1) {
                    printf("/");
                } else {
                    printf("\\");
                }
            }
            printf("\n");
        }
    }
    return 0;
}