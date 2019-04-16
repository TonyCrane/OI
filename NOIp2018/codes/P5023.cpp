/*************************************************************
 *  > File Name        : P5023.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月14日 星期日 10时24分55秒
**************************************************************/

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long LL;

int n, m;

LL poww(LL a, LL b) {
	LL res = 1; 
	for ( ; b; a = a * a % mod, b >>= 1){
		if (b & 1) {
			res = res * a % mod;
		}
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	if (n > m) swap(n, m);
	if (n == 1) printf("%lld\n", poww(2, m));
	else if (n == 2) printf("%lld\n", 4 * poww(3, m - 1) % mod);
	else if (n == 3) printf("%lld\n", 112 * poww(3, m - 3) % mod);
	else {
		if (m == n) printf("%lld\n", ((83 * poww(8, n) % mod + 5 * poww(2, n + 7) % mod) * 190104168 % mod));
		else printf("%lld\n", ((83 * poww(8, n) % mod + poww(2, n + 8)) * poww(3, m - n - 1) % mod * 570312504 % mod ));
	}
	return 0;
}
