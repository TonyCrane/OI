/*************************************************************
 *  > File Name        : c1063_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/27 12:30:42
 *  > Algorithm        : 链表
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 3000010;

struct Node {
    int l, r;
}a[maxn];

int n, m, ans[maxn];

int main() {
    n = read(); m = read();
	for (int i = 1; i <= n; i++) {
        a[i].l = i - 1;
        a[i].r = i + 1;
    }
	for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), x = read();
        int cnt = a[x].l;
		while (cnt >= l) {
			ans[cnt] = x;
			a[a[cnt].l].r = a[cnt].r;
			a[a[cnt].r].l = a[cnt].l;
			cnt = a[cnt].l;
		}
		cnt = a[x].r;
		while (cnt <= r) {
			ans[cnt] = x;
			a[a[cnt].l].r = a[cnt].r;
			a[a[cnt].r].l = a[cnt].l;
			cnt = a[cnt].r;
		}
	}
	for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
	printf("\n");
	return 0;
}