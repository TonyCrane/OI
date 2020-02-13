/*************************************************************
 *  > File Name        : c1000_7.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/15 12:41:34
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

int n, C, c[maxn];
int tot[maxn];

int main() {
    n = read(); C = read();
    for (int i = 1; i <= C; ++i) c[i] = read();
    tot[0] = 1;
    for (int i = 1; i <= C; ++i) {
		for (int j = c[i]; j <= n; ++j) {
			tot[j] += tot[j - c[i]];
		}
	}
    printf("%d\n", tot[n]);
    return 0;
}