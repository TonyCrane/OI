/*************************************************************
 *  > Description      : 数学相关模板
 *  > File Name        : Mathematics.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/05/07 14:46:56
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

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
 * @param[in]  n  最大值
 */
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
LL pow_mod(LL a, LL p, LL n){
    int res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
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

/**
 * @brief 矩阵乘法
 * @param[in]   A,B
 * @param[out]  res  A*B mod mod
 */
typedef long long Matrix[maxn][maxn];
int sz, mod;
void matrix_mul(Matrix A, Matrix B, Matrix res) {
    Matrix C;
    memset(C, 0, sizeof(C));
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < sz; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    memcpy(res, C, sizeof(C));
}

/**
 * @brief 矩阵快速幂
 * @param[in]   A,n
 * @param[out]  res  A^n mod mod
 */
void matrix_pow(Matrix A, int n, Matrix res) {
    Matrix a, r;
    memcpy(a, A, sizeof(a));
    memset(r, 0, sizeof(r));
    for (int i = 0; i < sz; ++i) r[i][i] = 1;
    while (n) {
        if (n & 1) matrix_mul(r, a, r);
        n >>= 1;
        matrix_mul(a, a, a);
    }
    memcpy(res, r, sizeof(r));
}

/**
 * @brief 矩阵乘列向量
 * @param[in]   d,A
 * @param[out]  res  A*d mod mod
 */
typedef long long Vector[maxn];
void transform(Vector d, Matrix A, Vector res) {
    Vector r;
    memset(r, 0, sizeof(r));
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            r[j] = (r[j] + d[i] * A[i][j]) % mod;
        }
    }
    memcpy(res, r, sizeof(r));
}

/**
 * @brief 高斯消元法
 * @param[in]  A,n
 */
const double eps = 1e-8;
void Gauss(double** A, int n) {
    int r;
    for (int i = 0; i < n; ++i) {
        r = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        }
        if (fabs(A[r][i]) < eps) {
            printf("No Solution\n");
            exit(0);
        }
        if (r != i) {
            for (int j = 0; j <= n; ++j) {
                swap(A[r][j], A[i][j]);
            }
        }
        for (int k = i + 1; k < n; ++k) {
            double f = A[k][i] / A[i][i];
            for (int j = i; j <= n; ++j) {
                A[k][j] -= f * A[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            A[i][n] -= A[j][n] * A[i][j];
        }
        A[i][n] /= A[i][i];
    }
}

/**
 * @brief 高斯-约当消元法
 * @param[in]  A,n
 */
void Gauss_jordan(double** A, int n) {
    int r;
    for (int i = 0; i < n; i++) {
        r = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if (fabs(A[r][i]) < eps) {
            printf("No Solution\n");
            exit(0);
        }
        if (r != i) {
            for (int j = 0; j <= n; j++) {
                swap(A[r][j], A[i][j]);
            }
        }
        for (int k = 0; k < n; k++) {
            if (k != i) {
                for (int j = n; j >= i; j--) {
                    A[k][j] -= A[k][i] / A[i][i] * A[i][j];
                }
            }
        }
    }
}

/**
 * @brief 矩阵求逆
 * @param[in]  a
 */
int n, is[410], js[410];
void inv(LL** a) {
    for (int k = 1; k <= n; ++k) {
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                if (a[i][j]) {
                    is[k] = i; js[k] = j; break;
                }
            }
        }
        for (int i = 1; i <= n; ++i) swap(a[k][i], a[is[k]][i]);
        for (int i = 1; i <= n; ++i) swap(a[i][k], a[i][js[k]]);
        if (!a[k][k]) {
            printf("No Solution\n");
            exit(0);
        }
        a[k][k] = inv(a[k][k], mod);
        for (int j = 1; j <= n; ++j)
            if (j != k) (a[k][j] *= a[k][k]) %= mod;
        for (int i = 1; i <= n; ++i)
            if (i != k) for (int j = 1; j <= n; ++j)
                if (j != k) (a[i][j] += mod - a[i][k] * a[k][j] % mod) %= mod;
        for (int i = 1; i <= n; ++i) 
            if (i != k) a[i][k] = (mod - a[i][k] * a[k][k] % mod) % mod;
    }
    for (int k = n; k; --k) {
        for (int i = 1; i <= n; ++i) swap(a[js[k]][i], a[k][i]);
        for (int i = 1; i <= n; ++i) swap(a[i][is[k]], a[i][k]);
    }
}

/**
 * @brief 拉格朗日插值
 * @param[in]  
 * @return 
 */
void Lagrange() {
    int n = read(), k = read(), x[2010], y[2010];
    for (int i = 0; i < n; ++i) x[i] = read(), y[i] = read();
    for (int i = 0; i < n; ++i) {
        long long tmp = 1;
        for (int j = 0; j < n; ++j) if (j != i) tmp = tmp * (x[i] - x[j] + mod) % mod;
        tmp = inv(tmp);
        for (int j = 0; j < n; ++j) if (j != i) tmp = tmp * (k - x[j] + mod) % mod;
        tmp = tmp * y[i] % mod;
        ans = (ans + tmp) % mod;
    }
}

/**
 * @brief 自适应辛普森法
 * @param[in]  f(x)
 * @return \int_l^r{f(x)dx}
 */

inline double f(double x);
inline double simpson(double l, double r) {
    double mid = (l + r) / 2;
    return (f(l) + 4 * f(mid) + f(r)) * (r - l) / 6;
}
double asr(double l, double r, double eps, double ans) {
    double mid = (l + r) / 2;
    double L = simpson(l, mid), R = simpson(mid, r);
    if (fabs(L + R - ans) <= 15 * eps) return L + R + (L + R - ans) / 15;
    return asr(l, mid, eps / 2, L) + asr(mid, r, eps / 2, R);
}
double integral(double l, double r, double eps) {
    return asr(l, r, eps, simpson(l, r));
}