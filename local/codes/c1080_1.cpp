/*************************************************************
 *  > File Name        : c1080_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/28 13:02:57
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 1000010;

LL vis[maxn];
LL prime[maxn], sum[maxn], num;
void getprime(LL n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= n; ++i) {
        if (vis[i] == 0) {
            vis[i] = i;
            prime[++num] = i;
        }
        for (int j = 1; j <= num; ++j) {
            if (prime[j] > vis[i] || prime[j] > n / i) break;
            vis[i * prime[j]] = prime[j];
        }
    }
}

int main() {
    LL T = read();
    getprime(1000000);
    // for (int i = 1; i <= num; ++i) {
    //     printf("%lld\n", prime[i]);
    // }
    for (LL i = 1; i <= num; ++i) sum[i] = sum[i - 1] + prime[i];
    while (T--) {
        LL n = read(), k = read();
        LL l = 1, r = num - k + 1, ans = -1;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            if (sum[mid + k - 1] - sum[mid - 1] <= n) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        if (sum[ans + k - 1] - sum[ans - 1] <= n && ans != -1) {
            printf("%lld\n", sum[ans + k - 1] - sum[ans - 1]);
        } else printf("-1\n");
    }
    return 0;
}