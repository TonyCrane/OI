/*************************************************************
 *  > File Name        : P2822.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/06 16:15:46
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

const int maxn = 2010;

int C[maxn][maxn], sum[maxn][maxn], k, n, m;

int main() {
    int T = read(); k = read();
    C[1][1] = 1;
    for (int i = 0; i <= 2000; ++i) C[i][0] = 1;
    for (int i = 2; i <= 2000; ++i) for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
    for (int i = 2; i <= 2000; ++i) {
        for (int j = 1; j <= i; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if (C[i][j] == 0) sum[i][j]++;
        }
        sum[i][i + 1] = sum[i][i];
    }
    while (T--) {
        n = read(); m = read();
        if (m > n) m = n;
        printf("%d\n", sum[n][m]);
    }
    return 0;
}