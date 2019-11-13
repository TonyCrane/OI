/*************************************************************
 *  > File Name        : c1089_2.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 16:15:44
 *  > Algorithm        : 
**************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
inline LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
 
const int maxn = 10010;
 
LL n, k, a[maxn], sum[maxn];
 
namespace Subtask1 {
    void work() {
        LL ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            sum[i] = sum[i - 1] + a[i];
            ans = min(ans, sum[i]);
        }
        printf("%lld\n", ans);
        return;
    }
}
 
namespace Subtask2 {
    LL dp[110][110], ans = 0x3f3f3f3f3f3f3f3f;
    void work() {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][1] = 0;
		ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            dp[i][1] = dp[i - 1][1] + a[i];
        }
        for (int l = k; l <= n; ++l) {
            for (int i = 1; i <= l; ++i) {
                for (int j = 2; j <= k; ++j) {
                    for (int m = 1; m < i; ++m) {
                        dp[i][j] = min(dp[i][j], max(dp[i][1] - dp[m][1], dp[m][j - 1]));
                    }
                }
            }
            ans = min(ans, dp[l][k]);
        }
        printf("%lld\n", ans);
        return;
    }
}
 
int main() {
    int T = read();
    while (T--) {
        n = read(); k = read();
        if (k == 1) Subtask1::work();
        else if (n <= 100) Subtask2::work();
    }
    return 0;
}