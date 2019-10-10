/*************************************************************
 *  > File Name        : c1073_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/10 14:55:45
 *  > Algorithm        : Previous Sum
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 510;

int n, m, q, G[maxn][maxn], u[maxn][maxn], l[maxn][maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            u[i][j] = u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
            l[i][j] = l[i - 1][j] + l[i][j - 1] - l[i - 1][j - 1]; 
            char ch = getchar();
            while (ch != '.' && ch != '#') ch = getchar();
            if (ch == '.') {
                G[i][j] = 1;
                if (G[i - 1][j] == 1) u[i][j] += 1;
                if (G[i][j - 1] == 1) l[i][j] += 1;
            }
        }
    }
    q = read();
    while (q--) {
        int r1 = read(), c1 = read();
        int r2 = read(), c2 = read();
        int up = u[r2][c2] - u[r1][c2] - u[r2][c1 - 1] + u[r1][c1 - 1];
        int le = l[r2][c2] - l[r2][c1] - l[r1 - 1][c2] + l[r1 - 1][c1];
        printf("%d\n", up + le);
    }
    return 0;
}