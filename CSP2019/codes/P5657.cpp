/*************************************************************
 *  > File Name        : P5657.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/23 12:23:56
 *  > Algorithm        : code
**************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
using namespace std;
typedef unsigned long long ull;

inline ull read() {
	ull x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 64;

ull n, k;

void dfs(ull n, ull k, ull rev, ull from) {
	if (n == 1) {
		if (rev == 0) {
			if (k == 0) printf("0");
			else printf("1");
		} else {
			if (k == 0) printf("1");
			else printf("0");
		}
		return;
	}
	if (k <= (1LL << (n - 1LL)) - 1LL) {
		if (rev == 0 && from == 0) {
			printf("0");
			dfs(n - 1LL, k, 0LL, 0LL);
		} else if (rev == 0 && from == 1) {
			printf("0");
			dfs(n - 1LL, k, 1LL, 0LL);
		} else if (rev == 1 && from == 0) {
			printf("1");
			dfs(n - 1LL, k, 0LL, 0LL);
		} else {
			printf("1");
			dfs(n - 1LL, k, 0LL, 0LL);
		}
	} else {
		if (rev == 0 && from == 0) {
			printf("1");
			dfs(n - 1LL, k - (1LL << (n - 1LL)), 1LL, 1LL);
		} else if (rev == 1 && from == 0) {
			printf("0");
			dfs(n - 1LL, k - (1LL << (n - 1LL)), 0LL, 1LL);
		} else if (rev == 0 && from == 1) {
			printf("1");
			dfs(n - 1LL, k - (1LL << (n - 1LL)), 0LL, 1LL);
		} else {
			printf("0");
			dfs(n - 1LL, k - (1LL << (n - 1LL)), 1LL, 1LL);
		}
	}
}

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);
	n = read(); k = read();
	dfs(n, k, 0, 0);
	printf("\n");
	return 0;
}