/*************************************************************
 *  > File Name        : P1621.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月22日 星期一 12时04分46秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int ufs[maxn], a, b, p, ans;
bool isprime[maxn];

int find(int x) {
	return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}

int main() {
	scanf("%d %d %d", &a, &b, &p);
	ans = b - a + 1;
	for (int i = a; i <= b; ++i) {
		ufs[i] = i;
	}
	for (int i = 2; i <= b; ++i) {
		if (!isprime[i]) {
			if (i >= p) {
				for (int j = i * 2; j <= b; j += i) {
					isprime[j] = true;
					if (j - i >= a && find(j) != find(j - i)) {
						ufs[find(j)] = find(j - i);
						--ans;
					}
				}
			} else {
				for (int j = i * 2; j <= b; j += i) {
					isprime[j] = true;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
