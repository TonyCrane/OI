/*************************************************************
 *  > File Name        : P5019.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月11日 星期四 12时18分08秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int n, d[maxn];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
	}
	for (int i = 2; i <= n; ++i) {
		if (d[i] > d[i - 1]) {
			ans += d[i] - d[i - 1];
		}
	}
	printf("%lld", ans + d[1]);
	return 0;
}
