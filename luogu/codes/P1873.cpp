/*************************************************************
 *  > File Name        : P1873.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月15日 星期一 12时56分37秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int l, r;
long long n, m, mid, ans;
int a[1000010];

bool check(int x) {
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > x) {
			res += a[i] - x;
		}
	}
	return res >= m;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		r = max(r, a[i]);
	}
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
