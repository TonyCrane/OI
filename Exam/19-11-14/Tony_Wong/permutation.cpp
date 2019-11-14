#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 100010;

int n, a[maxn];

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	next_permutation(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}
