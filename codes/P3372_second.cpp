/*************************************************************
 *  > File Name        : P3372_second.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年03月27日 星期三 16时08分56秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100010;

int n, m, opt, x, y, k;
LL sum[maxn << 2], add[maxn << 2];

inline int ls(int p) {
	return p << 1;
}

inline int rs(int p) {
	return p << 1|1;
}

void pushup(int p) {
	sum[p] = sum[ls(p)] + sum[rs(p)];
	return;
}

void pushdown(int p, int k) {
	if (add[p] == 0) return;
	add[ls(p)] += add[p];
	add[rs(p)] += add[p];
	sum[ls(p)] += add[p] * (k - (k >> 1));
	sum[rs(p)] += add[p] * (k >> 1);
	add[p] = 0;
}

void update(int p, int l, int r, int x, int y, int v) {
	if (x <= l && y >= r) {
		add[p] += v;
		sum[p] += 1LL * v * (r - l + 1);
		return;
	}
	pushdown(p, r - l + 1);
	int mid = l + r >> 1;
	if (x <= mid) update(ls(p), l, mid, x, y, v);
	if (y  > mid) update(rs(p), mid + 1, r, x, y, v);
	pushup(p);
}

void build(int p, int l, int r) {
	add[p] = 0;
	if (l == r) {
		scanf("%lld", &sum[p]);
		return;
	}
	int mid = l + r >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
	return;
}

LL query(int p, int l, int r, int x, int y) {
	if (x <= l && y >= r) return sum[p];
	pushdown(p, r - l + 1);
	int mid = l + r >> 1;
	LL res = 0;
	if (x <= mid) res += query(ls(p), l, mid, x, y);
	if (y  > mid) res += query(rs(p), mid + 1, r, x, y);
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d %d %d", &x, &y, &k);
			update(1, 1, n, x, y, k);
		} else if (opt == 2) {
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}
