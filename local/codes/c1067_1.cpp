/*************************************************************
 *  > File Name        : c1067_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 12:50:36
 *  > Algorithm        : ST
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

int n;
LL ans;
int a[maxn], _fmax[maxn][21], _fmin[maxn][21];
int pos[maxn];

void funcmax(int l, int r) {
    if (l > r) return;
    int s = log2(r - l + 1);
    int maxx = max(_fmax[l][s], _fmax[r - (1 << s) + 1][s]);
    int now = pos[maxx];
    ans += (LL)maxx * (now - l + 1) * (r - now + 1);
    funcmax(l, now - 1);
    funcmax(now + 1, r);
}

void funcmin(int l, int r) {
    if (l > r) return;
    int s = log2(r - l + 1);
    int minn = min(_fmin[l][s], _fmin[r - (1 << s) + 1][s]);
    int now = pos[minn];
    ans -= (LL)minn * (now - l + 1) * (r - now + 1);
    funcmin(l, now - 1);
    funcmin(now + 1, r);
}

int main() {
    int T = read();
    while (T--) {
        n = read(); ans = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            _fmax[i][0] = a[i];
            _fmin[i][0] = a[i];
            pos[a[i]] = i;
        }
        for (int j = 1; j <= 20; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                _fmax[i][j] = max(_fmax[i][j - 1], _fmax[i + (1 << j - 1)][j - 1]);
                _fmin[i][j] = min(_fmin[i][j - 1], _fmin[i + (1 << j - 1)][j - 1]);
            }
        }
        funcmax(1, n);
        funcmin(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}