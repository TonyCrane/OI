/*************************************************************
 *  > File Name        : T92971.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 09:59:13
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)? EOF : *p1++;
}
inline int read() {
    int x = 0; int f = 1; char ch = nc();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = nc();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = nc();}
    return x * f;
}

const int maxn = 1010;

int n, m, Q, a[maxn][maxn], dp[maxn][maxn], b[maxn][maxn];

int qMax(int _x1, int _y1, int _x2, int _y2) {
    int ans = -1;
    for (int i = _x1; i <= _x2; ++i) {
        for (int j = _y1; j <= _y2; ++j) {
            ans = max(ans, a[i][j]);
        }
    }
    return ans;
}

int qSum(int _x1, int _y1, int _x2, int _y2) {
    int ans = 0;
    for (int i = _x1; i <= _x2; ++i) {
        for (int j = _y1; j <= _y2; ++j) {
            ans += a[i][j];
        }
    }
    return ans;
}

int qBest(int _x1, int _y1, int _x2, int _y2) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= _x1 && i <= _x2 && j >= _y1 && j <= _y2)
                dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]) + b[i][j]);
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][n];
} 

int main() {
    n = read(); m = read(); Q = read(); int cnt = 0;
    while (Q--) {
        int opt = read(), _x1 = read(), _y1 = read(), _x2 = read(), _y2 = read();
        if (opt > 0) { ++cnt;
            for (int i = _x1; i <= _x2; ++i) {
                for (int j = _y1; j <= _y2; ++j) {
                    a[i][j] += opt;
                }
            }
            if (cnt <= m) {
                for (int i = _x1; i <= _x2; ++i) {
                    for (int j = _y1; j <= _y2; ++j) {
                        b[i][j] += opt;
                    }
                }
            }
        } else if (opt == 0) {
            printf("%d\n", qMax(_x1, _y1, _x2, _y2));
        } else if (opt == -1) {
            printf("%d\n", qSum(_x1, _y1, _x2, _y2));
        }
    }
    printf("%d\n", qBest(1, 1, n, n));
    return 0;
}