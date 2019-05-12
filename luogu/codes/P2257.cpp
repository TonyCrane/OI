/*************************************************************
 *  > File Name        : P2257.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/12 16:30:54
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000010;

bool vis[maxn];
long long sum[maxn];
int mu[maxn], primes[maxn], g[maxn], cnt;
void get_mu(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) { primes[++cnt] = i; mu[i] = -1; }
		for (int j = 1; j <= cnt && primes[j] * i <= n; ++j) {
			vis[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
			else mu[i * primes[j]] = -mu[i];
		}
	}
    for (int j = 1; j <= cnt; ++j) 
        for (int i = 1; i * primes[j] <= n; ++i)
            g[i * primes[j]] += mu[i];
    for (int i = 1; i <= n; ++i) 
        sum[i] = sum[i - 1] + (long long)g[i];
}

int n, m;

int main() {
    int T;
    scanf("%d", &T);
    get_mu(maxn - 10);
    while (T--) {
        scanf("%d %d", &n, &m);
        if (n > m) swap(n, m);
        long long ans = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            ans += 1LL * (n / l) * (m / l) * (sum[r] - sum[l - 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}