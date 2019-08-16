/*************************************************************
 *  > File Name        : 1124.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/16 12:07:07
 *  > Algorithm        : DP+bit
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
inline LL readll() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

int n, A, B;
LL d[maxn], s[maxn];

namespace Aeq1 {
    bool able[maxn];
    int dp[maxn];

    bool check(LL old, LL tar) {
        memset(able, 0, sizeof(able));
        memset(dp, 0x3f, sizeof(dp));
        able[0] = true; dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (able[j] && ( (s[i] - s[j]) | old ) < tar) {
                    able[i] = true;
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        if (able[n] && dp[n] <= B) {
            return true;
        } else return false;
    }

    void solve() {
        int max_bit = 0;
        LL sum = s[n] << 1;
        for (; sum >> max_bit; max_bit++); max_bit--;
        LL ans = 0;
        for (int i = max_bit; i >= 0; --i) {
            LL tar = ans | (1LL << i);
            if (!check(ans, tar)) {
                ans += (1LL << i);
            }
        }
        printf("%lld\n", ans);
    }
}

namespace Aneq1 {
    bool able[maxn][maxn];

    bool check(LL old, LL tar) {
        memset(able, 0, sizeof(able));
        able[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= B; ++j) {
                for (int k = i - 1; k >= 0; --k) {
                    if (able[k][j - 1] && ( (s[i] - s[k]) | old ) < tar) {
                        able[i][j] = true;
                        break;
                    }
                }
            }
        }
        for (int i = A; i <= B; ++i) {
            if (able[n][i]) {
                return true;
            }
        }
        return false;
    }

    void solve() {
        int max_bit = 0;
        LL sum = s[n] << 1;
        for (; sum >> max_bit; max_bit++); max_bit--;
        LL ans = 0;
        for (int i = max_bit; i >= 0; --i) {
            LL tar = ans | (1LL << i);
            if (!check(ans, tar)) {
                ans += (1LL << i);
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
    n = read(); A = read(); B = read();
    for (int i = 1; i <= n; ++i) {
        d[i] = readll();
        s[i] = s[i - 1] + d[i];
    }
    if (A == 1) {
        Aeq1::solve();
    } else {
        Aneq1::solve();
    }
    return 0;
}