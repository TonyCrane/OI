/*************************************************************
 *  > File Name        : P2522.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 14:18:49
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 50010;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int mu[maxn], primes[maxn], cnt, k;
bool vis[maxn];
LL sum[maxn];

void get_mu(int n) {
	memset(vis, 0, sizeof(vis));
	memset(mu, 0, sizeof(mu));
	cnt = 0; mu[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) { primes[cnt++] = i; mu[i] = -1; }
		for (int j = 0; j < cnt && primes[j] * i <= n; ++j) {
			vis[primes[j] * i] = 1;
			if (i % primes[j] == 0)break;
			mu[i * primes[j]] = -mu[i];
		}
	}
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + mu[i];
    }
}

LL solve(int n, int m) {
    int rep = min(n, m); LL ans = 0;
    for (int l = 1, r; l <= rep; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        ans += (1ll * n / (1ll * l * k)) * (1ll * m / (1ll * l * k)) * (sum[r] - sum[l - 1]);
    }
    return ans;
}

int main() {
    int T = read();
    get_mu(50000);
    while (T--) {
        int a = read(), b = read(), c = read(), d = read(); k = read();
        LL ans = solve(b, d) - solve(b, c - 1) - solve(a - 1, d) + solve(a - 1, c - 1);
        printf("%lld\n", ans);
    }
    return 0;
}