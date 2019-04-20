/*************************************************************
 *  > File Name        : U68608.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月20日 星期六 15时03分11秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, l, g, w, h;

int main() {
	scanf("%d %d %d", &n, &l, &g);
	while (n--) {
		scanf("%d %d", &w, &h);
		while (w > g || h > g) {
			w /= 2; h /= 2;
		}
		if (w < l || h < l) {
			printf("Too Young\n");
		} else if (w >= l && h >= l && w != h) {
			printf("Too Simple\n");
		} else if (w >= l && h >= l && w == h) {
			printf("Sometimes Naive\n");
		}
	}
	return 0;
}
