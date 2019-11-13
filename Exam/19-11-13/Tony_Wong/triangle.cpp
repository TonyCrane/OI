#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 110;

int n;

int main() {
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	n = read();
	if (n < 6) {
		printf("0\n");
		return 0;
	}
	if (n == 6) {
		printf("1\n");
	} else if (n == 7) {
		printf("7\n");
	} else if (n == 8) {
		printf("28\n");
	} else {
		long long m = (long long)n;
		printf("%lld\n", m * (m - 1) * (m - 2) * (m - 3) * (m - 4) * (m - 5) / 720);
	}
	return 0;
}
