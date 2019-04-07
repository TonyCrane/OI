/*************************************************************
 *  > File Name        : P1541.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月19日 星期三 12时46分33秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, m, c, a[400], cnt[130], dp[45][45][45][45];

int main()
{
    scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i) scanf("%d", &c), cnt[c]++;
	dp[0][0][0][0] = a[1];
	for (int i = 0; i <= cnt[1]; ++i)
		for (int j = 0; j <= cnt[2]; ++j)
			for (int k = 0; k <= cnt[3]; ++k)
				for (int l = 0; l <= cnt[4]; ++l)
				{
					int x = i + j * 2 + k * 3 + l * 4 + 1;
					if (i != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[x]);
					if (j != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[x]);
					if (k != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[x]);
					if (l != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[x]);
				}
	printf("%d\n", dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}
