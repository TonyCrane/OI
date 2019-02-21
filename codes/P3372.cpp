/*************************************************************
 *  > File Name        : P3372.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月21日 星期四 12时31分17秒
**************************************************************/

#include <bits/stdc++.h>
#define LL long long
#define ls rt<<1
#define rs rt<<1|1
using namespace std;

const int maxn = 100010;

LL sum[maxn << 2], add[maxn << 2];
int n, q, opt, t1, t2, t3;

void pushup(int rt)
{
	sum[rt] = sum[ls] + sum[rs];
}

void pushdown(int rt, int k)
{
	if (!add[rt]) return;
	add[ls] += add[rt];
	add[rs] += add[rt];
	sum[ls] += add[rt] * (k - (k >> 1));
	sum[rs] += add[rt] * (k >> 1);
	add[rt] = 0;
}

void update(int rt, int l, int r, int ql, int qr, int k)
{
	if (ql <= l && qr >= r)
	{
		add[rt] += k;
		sum[rt] += 1LL * k * (r - l + 1);
		return;
	}
	pushdown(rt, r - l + 1);
	int mid = (l + r) >> 1;
	if (ql <= mid)
	{
		update(ls, l, mid, ql, qr, k);
	}
	if (qr > mid)
	{
		update(rs, mid + 1, r, ql, qr, k);
	}
	pushup(rt);
}

void build(int rt, int l, int r)
{
	add[rt] = 0;
	if (l == r)
	{
		scanf("%lld", &sum[rt]);
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(rt);
}

LL query(int rt, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r) return sum[rt];
	pushdown(rt, r - l + 1);
	int mid = (l + r) >> 1;
	LL ans = 0;
	if (ql <= mid)
	{
		ans += query(ls, l, mid, ql, qr);
	}
	if (qr > mid)
	{
		ans += query(rs, mid + 1, r, ql, qr);
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	while (q--)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d %d %d", &t1, &t2, &t3);
			update(1, 1, n, t1, t2, t3);
		}
		if (opt == 2)
		{
			scanf("%d %d", &t1, &t2);
			printf("%lld\n", query(1, 1, n, t1, t2));
		}
	}
	return 0;
}
