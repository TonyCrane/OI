/*************************************************************
 *  > File Name        : P3373.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年03月28日 星期四 15时01分01秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, p, opt, x, y, k;





int main() {
	scanf("%d %d %d", &n, &m, &p);
	build(1, 1, n);
	while (m--) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d %d %d", &x, &y, &k);
			updateMul(1, 1, n, x, y, k);
		} else if (opt == 2) {
			scanf("%d %d %d", &x, &y, &k);
			updateAdd(1, 1, n, x, y, k);
		} else if (opt == 3) {
			scanf("%d %d", &x, &y);
			printf("%d\n", query(1, 1, n, x, y);
		}
	}
	return 0;
}
