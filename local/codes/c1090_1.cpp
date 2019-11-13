/*************************************************************
 *  > File Name        : c1090_1.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 11:36:26
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
	return x * f;
}

const int maxn = 100010;

int n, x, a[maxn];
int cnt = 0, ans[maxn], dp[maxn], tot[maxn];

int main() {
	// freopen("coin.in", "r", stdin);
	// freopen("coin.out", "w", stdout);
	n = read(); x = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	tot[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = x; j >= a[i]; --j) {
			tot[j] += tot[j - a[i]];
		}
	}
	for (int i = 1; i <= n; ++i) {
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j <= x; ++j) {
			if (j < a[i]) dp[j] = tot[j];
			else dp[j] = tot[j] - dp[j - a[i]];
		}
		if (!dp[x]) {
			ans[++cnt] = a[i];
		}
	}
	if (cnt == 0) {
		printf("0\n\n");
	} else {
		sort(ans + 1, ans + 1 + cnt);
		int len = unique(ans + 1, ans + 1 + cnt) - ans - 1;
		printf("%d\n", len);
		for (int i = 1; i <= len; ++i) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
