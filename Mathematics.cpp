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
LL mul_mod(LL a, LL b, int n) {
    a %= n; b %= n; return a * b % n;
}

/**
 * @brief a^p mod n(快速幂)
 * @param[in]  a,p,n
 * @return a^p mod n
 */
LL pow_mod(LL a, LL p, LL n) {
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