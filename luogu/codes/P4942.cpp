/*************************************************************
 *  > File Name        : P4942.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月22日 星期一 12时14分42秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int T;
long long l, r, tmp, ans;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld %lld", &l, &r);
		tmp = (r - l + 1) % 9;
		ans = (tmp * (l % 9) % 9 + tmp * (tmp - 1) % 9 * 5 % 9) % 9;
		printf("%lld\n", ans);
	}
	return 0;
}
