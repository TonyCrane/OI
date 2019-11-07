/*************************************************************
 *  > File Name        : c1086_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/07 15:32:56
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

int n, _x[maxn], _y[maxn], _x1, _x2, _y1, _y2;

int main() {
    int T = read();
    while (T--) {
        n = read();
        memset(_x, 0, sizeof(_x));
        memset(_y, 0, sizeof(_y));
        _x1 = read(); _y1 = read(); _x2 = read(); _y2 = read();
        for (int i = 1; i <= n; ++i) {
            _x[i] = read(); _y[i] = read();
        }
        int m = read();
        for (int i = 1; i <= m; ++i) {
            int opt = read(), l = read(), r = read();
            if (opt == 1) {
                int d = read();
                for (int j = l; j <= r; ++j) {
                    _x[j] += d;
                }
            } else if (opt == 2) {
                int d = read();
                for (int j = l; j <= r; ++j) {
                    _y[j] += d;
                }
            } else {
                int ans = 0;
                for (int j = l; j <= r; ++j) {
                    if (_x[j] >= _x1 && _x[j] <= _x2 && _y[j] >= _y1 && _y[j] <= _y2) {
                        ans++;
                    }
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}