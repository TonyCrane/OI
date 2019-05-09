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

/**
 * @brief 欧拉φ函数
 * @param[in]  n  终止值
 * @return φ(n)
 */
int euler_phi(int n) {
    int m = (int)sqrt(n + 0.5); int ans = n;
    for (int i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
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