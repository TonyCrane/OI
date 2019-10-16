/*************************************************************
 *  > File Name        : suspect.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/16 12:51:39
 *  > Algorithm        : 80 Points
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

const int maxn = 300010;

int n, p;

namespace Subtask1 {
    void work() {
        printf("%lld\n", (LL)n * (n - 1) / 2);
    }
}

namespace Subtask2 {
    LL deg[maxn], t = 0;
    void work() {
        for (int i = 1; i <= n; ++i) {
            int x = read(), y = read();
            deg[x]++; deg[y]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 0) {
                t++;
            }
        }
        LL dans = t * (t - 1) / 2;
        printf("%lld\n", (LL)n * (n - 1) / 2 - dans);
    }
}

namespace Subtask3 {
    bitset<1010> G[1010];
    void work() {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = read(), y = read();
            G[x][i] = 1; G[y][i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                bitset<1010> tmp;
                tmp = G[i] | G[j];
                if (tmp.count() >= p) ans++;
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    n = read(); p = read();
    if (p == 0) {
        Subtask1::work();
    } else if (p == 1) {
        Subtask2::work();
    } else if (n <= 1000) {
        Subtask3::work();
    }
    return 0;
}