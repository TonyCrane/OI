/*************************************************************
 *  > Description      : 数学相关模板
 *  > File Name        : Mathematics.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/07 14:46:56
 *  > Copyright (C) 2019 Tony
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010;

/**
 * @brief 欧几里得算法
 * @param[in]  a,b
 * @return a和b的最大公因数
 */
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

/**
 * @brief 扩展欧几里得算法
 * @param[in]   a,b
 * @param[out]  d    gcd(a,b)
 * @param[out]  x,y  一组解
 */
void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

/**
 * @brief Eratosthenes筛法
 * @param[in]  n  终止
 */
bool vis[maxn];
int prime[maxn];
void getprime(int n) {
    int m = (int)sqrt(n + 0.5), num = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= m; ++i) if (!vis[i]) {
        prime[++num] = i;
        for (int j = i * i; j <= n; j += i) vis[j] = 1;
    }
}

/**
 * @brief ab mod n
 * @param[in]  a,b,n
 * @return ab mod n
 */
LL mul_mod(LL a, LL b, LL n){
    LL res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}

/**
 * @brief a^p mod n(快速幂)
 * @param[in]  a,p,n
 * @return a^p mod n
 */
LL pow_mod(LL a, LL p, LL n) {
    if (p == 0 && n == 1) return 0;
    if (p == 0) return 1;
    LL ans = pow_mod(a, p / 2, n); ans = ans * ans % n;
    if (p % 2 == 1) ans = ans * a % n;
    return ans;
}
LL pow_mod(LL a, LL p, LL n) { //位运算
    a %= n; LL ans = 1;
    for (; p; p >>= 1, a *= a, a %= n)
        if(p & 1) ans = ans * a % n;
    return ans;
}

/**
 * @brief 欧拉φ函数
 * @param[in]  n
 * @return φ(n)
 */
int euler_phi(int n) {
    int m = (int)sqrt(n + 0.5); int ans = n;
    for (int i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

/**
 * @brief 生成欧拉函数表
 * @param[in]  n
 */
int phi[maxn];
void phi_table(int n) {
    for (int i = 2; i <= n; ++i) phi[i] = 0; phi[1] = 1;
    for (int i = 2; i <= n; ++i) if (!phi[i])
        for (int j = i; j <= n; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
}

/**
 * @brief 乘法逆元
 * @param[in]  a,n  原数,模数
 * @return 乘法逆元
 */
LL inv(LL a, LL n) {
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

/**
 * @brief 生成逆元表
 * @param[in]  n
 */
int inv_table[maxn];
void getinv(int n, int p) {
    inv_table[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv_table[i] = (LL)(p - p / i) * inv_table[p % i] % p;
    }
}

/**
 * @brief 中国剩余定理(China Remainder Theorem)
 * @param[in]  n,*a,*m
 * @return 同余方程组x≡a[i] (mod m[i])的解
 */
LL crt(int n, int* a, int* m) {
    LL M = 1, d, y, x = 0;
    for (int i = 0; i < n; ++i) M *= m[i];
    for (int i = 0; i < n; ++i) {
        LL w = M / m[i];
        exgcd(m[i], w, d, d, y);
        x = (x + y * w * a[i]) % M;
    }
    return (x + M) % M;
}

/**
 * @brief 扩展中国剩余定理(m不两两互质)
 * @param[in]  n,*a,*m
 * @return 同余方程组x≡a[i] (mod m[i])的解
 */
LL excrt(LL n, LL* a, LL* m) {
    LL x, y, k, M = m[0], ans = a[0];
    for (int i = 1; i < n; ++i) {
        LL A = M, B = m[i], C = (a[i] - ans % B + B) % B, gcd;
        exgcd(A, B, gcd, x, y);
        LL bg = B / gcd;
        if (C % gcd != 0) return -1;
        x = mul_mod(x, C / gcd, bg);
        ans += x * M; M *= bg;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}

/**
 * @brief 离散对数(指数同余方程) BSGS算法
 * @param[in]  a,b,n
 * @return 方程a^x≡b (mod n)的解 
 */
int log_mod(int a, int b, int n) {
    int m, v, e = 1, i;
    m = (int)sqrt(n + 0.5);
    v = inv(pow_mod(a, m, n), n);
    map<int, int> x;
    x[1] = 0;
    for (i = 1; i < m; ++i) {
        e = mul_mod(e, a, n);
        if (!x.count(e)) x[e] = i;
    }
    for (i = 0; i < m; ++i) {
        if (x.count(b)) return i * m + x[b];
        b = mul_mod(b, v, n);
    }
    return -1;
}

/**
 * @brief 整除分块(∑_{i=1}^n{k mod i})
 * @param[in]  n,k
 */
void block(LL n, LL k) {
    LL ans = 0;
    for (long long l = 1, r, t; l <= n; l = r + 1) {
        t = k / l;
        if (t) r = min(k / t, n);
        else r = n;
        ans += t * (r - l + 1) * (l + r) / 2;
    }
    printf("%lld\n", n * k - ans);
}

/**
 * @brief 线性筛莫比乌斯函数
 * @param[in]  n
 */
int mu[maxn], vis[maxn];
int primes[maxn], cnt;
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
}

/**
 * @brief Miller-Rabin素数测试
 * @param[in]  n
 * @return bool值(是否为素数)
 */
LL Random(LL n) { return (LL)((double)rand() / RAND_MAX * n + 0.5); }
bool Witness(LL a, LL n) {
    LL m = n - 1; int j = 0;
    while (!(m & 1)) { j++; m >>= 1; }
    LL x = pow_mod(a, m, n);
    if (x == 1 || x == n - 1) return false;
    while (j--) { x = x * x % n; if (x == n - 1) return false; }
    return true;
}
bool Miller_Rabin(LL n) {
    if (n < 2) return false; if (n == 2) return true;
    if (!(n & 1)) return false;
    for (int i = 1; i <= 30; ++i) {
        LL a = Random(n - 2) + 1;
        if (Witness(a, n)) return false;
    }
    return true;
}

/**
 * @brief Rollard-Rho算法
 * @param[in]   n
 * @param[out]  maxx  最大质因子
 * @param[out]  mini  最小质因子
 */
LL maxx, mini;
LL vis[510];
LL Pollard_Rho(LL n, int c) {
    LL x, y, d, i = 1, k = 2;
    x = Random(n - 1) + 1; y = x;
    while (true) {
        i++;
        x = (mul_mod(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if (1 < d && d < n) return d;
        if (y == x) return n;
        if (i == k) { y = x; k <<= 1; }
    }
}
void find(LL n, int k) {
    if (n == 1) return;
    if (Miller_Rabin(n)) {
        vis[++cnt] = n;
        if (n > maxx) maxx = n;
        if (n < mini) mini = n;
        return;
    }
    LL p = n;
    while (p >= n) p = Pollard_Rho(p, k--);
    find(p, k); find(n / p, k);
}

/**
 * @brief Lucas定理
 * @param[in]  n,m,p
 * @return C(n,m) mod p
 */
LL c[maxn]; int p;
LL C(LL a, LL b) {
    if (a < b) return 0;
    return ((c[a] * pow_mod(c[b], p - 2, p)) % p * pow_mod(c[a - b], p - 2, p) % p);
}
LL Lucas(LL n, LL m) {
    if (m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
void getc(int p) {
    c[0] = 1;
    for (int i = 1; i <= p; ++i) c[i] = (c[i - 1] * i) % p;
}

/**
 * @brief 扩展Lucas定理
 * @param[in]  n,m,p
 * @return C(n, m) mod p
 */

LL a[maxn], c[maxn], n, m, p, cnt;
inline LL crt(){
    LL M = 1, ans = 0;
    for (int i = 0; i < cnt; ++i) M *= c[i];
    for (int i = 0; i < cnt; ++i) {
        ans = (ans + a[i] * (M / c[i]) % M * inv(M / c[i], c[i]) % M) % M;
    }
    return ans;
}
LL fac(LL n, LL p, LL pk) {
    if (!n) return 1; LL ans = 1;
    for (int i = 1; i < pk; ++i)
        if (i % p) ans = ans * i % pk;
    ans = pow_mod(ans, n / pk, pk);
    for (int i = 1; i <= n % pk; ++i)
        if (i % p) ans = ans * i % pk;
    return ans * fac(n / p, p, pk) % pk;
}
LL C(LL n, LL m, LL p, LL pk) {
    if (n < m) return 0;
    LL N = fac(n, p, pk), M = fac(m, p, pk), Z = fac(n - m, p, pk), cnt = 0;
    for (LL i = n; i; i /= p) cnt += i / p;
    for (LL i = m; i; i /= p) cnt -= i / p;
    for (LL i = n - m; i; i /= p) cnt -= i / p;
    return N * inv(M, pk) % pk * inv(Z, pk) % pk * pow_mod(p, cnt, pk) % pk;
}
LL exLucas(LL n, LL m, LL p) {
    LL tmp = sqrt(p);
    for (int i = 2; p > 1 && i <= tmp; ++i) {
        LL tmp = 1;
        while (p % i == 0) p /= i, tmp *= i;
        if (tmp > 1) c[cnt] = tmp, a[cnt++] = C(n, m, i, tmp);
    }
    if (p > 1) c[cnt] = p, a[cnt++] = C(n, m, p, p);
    return crt();
}

/**
 * @brief 杜教筛
 * @param[in]  n
 * @return ∑_{i=1}^n{φ(i)} ∑_{i=1}^n{μ(i)}
 */
#include <tr1/unordered_map>
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