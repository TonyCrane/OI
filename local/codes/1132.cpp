/*************************************************************
 *  > File Name        : 1132.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 12:18:47
 *  > Algorithm        : 模拟
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2010;

int n, m, ans;
char s[maxn][maxn];
int rnk[maxn], nxt[maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }
    for (int j = 1; j <= m; ++j) {
        bool del = false;
        nxt[1] = 0;
        for (int i = 1; i < n; ++i) {
            if (rnk[i] < rnk[i + 1]) {
                nxt[i + 1] = nxt[i] + 1;
                continue;
            } else {
                if (s[i][j] > s[i + 1][j]) {
                    ans++;
                    del = true;
                    break;
                } else if (s[i][j] == s[i + 1][j]) {
                    nxt[i + 1] = nxt[i];
                } else {
                    nxt[i + 1] = nxt[i] + 1;
                }
            }
        }
        if (!del) {
            for (int i = 1; i <= n; ++i) {
                rnk[i] = nxt[i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}