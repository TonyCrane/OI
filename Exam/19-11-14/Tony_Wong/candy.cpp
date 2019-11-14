#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
	LL x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const LL maxn = 100010;
const LL mod  = 10000007;

LL n, k, a[maxn];
LL ans, max1 = -0x3f3f3f3f3f3f3f3f, max2 = -0x3f3f3f3f3f3f3f3f;

struct Matrix {
    LL mat[2][2];
    Matrix() { memset(mat, 0, sizeof(mat)); }
    Matrix operator * (const Matrix& a) const {
        Matrix res; memset(res.mat, 0, sizeof(res.mat));
        for (LL i = 0; i < 2; ++i) {
            for (LL j = 0; j < 2; ++j) {
                for (LL k = 0; k < 2; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
}Base, Fib;

void Matrix_pow(LL pow) {
    while (pow) {
        if (pow & 1) Fib = Fib * Base;
        Base = Base * Base;
        pow >>= 1;
    }
}

int main() {
	n = read(); k = read();
	for (LL i = 1; i <= n; ++i) { 
		a[i] = read();
		ans = (ans + a[i] + mod * 10) % mod;
		if (a[i] > max1) {
			max2 = max1;
			max1 = a[i];
		} else if (a[i] > max2) {
			max2 = a[i];
		}
	}
	// printf("ans = %d, max1 = %d, max2 = %d\n", ans, max1, max2);
	if (max1 > 0) {
		Base.mat[0][0] = 1; Base.mat[0][1] = 1;
    	Base.mat[1][0] = 1; Base.mat[1][1] = 0;
    	Fib.mat[0][0] = Fib.mat[0][1] = 1;
		if (k + 1 >= 3) Matrix_pow(k + 1);
		LL fibkm1p2 = Fib.mat[0][1];
		LL fibkp2 = Fib.mat[0][0];
		// printf("fibk+2 = %lld, fibk-1+2 = %lld\n", fibkp2, fibkm1p2);
		printf("%lld\n", (ans + (fibkp2 - 2) * max1 % mod + (fibkm1p2 - 1) * max2 % mod + mod * 10) % mod);
	} else {
		printf("%lld\n", (ans + k * (max1 + max2) % mod + mod * 10) % mod);
	}
	return 0;
}
