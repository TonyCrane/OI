/*************************************************************
 *  > File Name        : P4213.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/16 16:19:29
**************************************************************/

#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
typedef long long LL;

const int maxn = 5000010;

tr1::unordered_map<int, LL> Smu, Sphi;
int primes[maxn], cnt;
LL mu[maxn], phi[maxn];
bool vis[maxn];

void get() {
    mu[1] = 1; phi[1] = 1;
    for (int i = 2; i <= maxn - 10; ++i) {
        if (!vis[i]) { primes[++cnt] = i; mu[i] = -1; phi[i] = i - 1; }
        for (int j = 1; j <= cnt && i * primes[j] <= maxn - 10; ++j) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) { phi[i * primes[j]] = phi[i] * primes[j]; break; }
            else mu[i * primes[j]] = -mu[i], phi[i * primes[j]] = phi[i] * phi[primes[j]];
        }
    }
    for (int i = 1; i <= maxn - 10; ++i) {
        mu[i] += mu[i - 1];
        phi[i] += phi[i - 1];
    }
}

LL djsmu(int n) {
    if (n <= maxn - 10) return mu[n];
    if (Smu[n]) return Smu[n];
    LL res = 1LL;
    for (int l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l); res -= (r - l + 1) * djsmu(n / l);
    }
    return Smu[n] = res;
}

LL djsphi(int n) {
    if (n <= maxn - 10) return phi[n];
    if (Sphi[n]) return Sphi[n];
    LL res = (1LL + n) * n / 2;
    for (int l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l); res -= (r - l + 1) * djsphi(n / l);
    }
    return Sphi[n] = res;
}

int main() {
    get(); int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        printf("%lld %lld\n", djsphi(n), djsmu(n));
    }
    return 0;
}