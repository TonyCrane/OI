/*************************************************************
 *  > File Name        : P5020.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月11日 星期四 12时25分12秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, T, ans, a[1010], dp[30010];

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, -0x3f, sizeof(dp));
		memset(a, 0, sizeof(a));
		ans = 0; dp[0] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = a[i]; j <= 25010; ++j) {
				dp[j] = max(dp[j], dp[j - a[i]] + 1);
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (dp[a[i]] == 1) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
