/*************************************************************
 *  > File Name        : P3372.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 15:42:34
 *  > Algorithm        : [DataStructure]Block
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

LL a[maxn], sum[maxn], add[maxn];
int L[maxn], R[maxn];
int pos[maxn];
int n, m, t;

void change(int l, int r, LL d) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; ++i) a[i] += d;
		sum[p] += d * (r - l + 1);
	} else {
		for (int i = p + 1; i <= q - 1; ++i) add[i] += d;
		for (int i = l; i <= R[p]; ++i) a[i] += d;
		sum[p] += d * (R[p] - l + 1);
		for (int i = L[q]; i <= r; ++i) a[i] += d;
		sum[q] += d * (r - L[q] + 1);
	}
}

LL query(int l, int r) {
	int p = pos[l], q = pos[r];
	LL ans = 0;
	if (p == q) {
		for (int i = l; i <= r; ++i) ans += a[i];
		ans += add[p] * (r - l + 1);
	} else {
		for (int i = p + 1; i <= q - 1; ++i) ans += sum[i] + add[i] * (R[i] - L[i] + 1);
		for (int i = l; i <= R[p]; ++i) ans += a[i];
		ans += add[p] * (R[p] - l + 1);
		for (int i = L[q]; i <= r; ++i) ans += a[i];
		ans += add[q] * (r - L[q] + 1);
	}
	return ans;
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	t = sqrt(n * 1.0);
	for (int i = 1; i <= t; ++i) {
		L[i] = (i - 1) * t + 1;
		R[i] = i * t;
	}
	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
	for (int i = 1; i <= t; ++i) {
		for (int j = L[i]; j <= R[i]; ++j) {
			pos[j] = i;
			sum[i] += a[j];
		}
    }
	while (m--) {
		int opt = read(), l = read(), r = read(), d;
		if (opt == 1) {
            d = read();
			change(l, r, d);
		} else printf("%lld\n", query(l, r));
	}
    return 0;
}