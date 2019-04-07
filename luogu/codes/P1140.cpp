#include<bits/stdc++.h>
using namespace std;

int lena, lenb, a[110], b[110], dp[110][110];
char A[110], B[110];

int sim[5][5] = {{ 5, -1, -2, -1, -3},
				 {-1,  5, -3, -2, -4},
			     {-2, -3,  5, -2, -2},
			     {-1, -2, -2,  5, -1},
				 {-3, -4, -2, -1,  0}};

int main()
{
	scanf("%d %s", &lena, A);
	scanf("%d %s", &lenb, B);
	for (int i = 1; i <= lena; ++i)
	{
		if (A[i - 1] == 'A') a[i] = 0;
		if (A[i - 1] == 'C') a[i] = 1;
		if (A[i - 1] == 'G') a[i] = 2;
		if (A[i - 1] == 'T') a[i] = 3;
	}
	for (int i = 1; i <= lenb; ++i)
	{
		if (B[i - 1] == 'A') b[i] = 0;
		if (B[i - 1] == 'C') b[i] = 1;
		if (B[i - 1] == 'G') b[i] = 2;
		if (B[i - 1] == 'T') b[i] = 3;
	}
	for (int i = 1; i <= lena; ++i)
		for (int j = 1; j <= lenb; ++j)
			dp[i][j] = -1e9;
	for (int i = 1; i <= lena; ++i) dp[i][0] = dp[i - 1][0] + sim[a[i]][4];
	for (int i = 1; i <= lenb; ++i) dp[0][i] = dp[0][i - 1] + sim[b[i]][4];
	for (int i = 1; i <= lena; ++i)
		for (int j = 1; j <= lenb; ++j)
		{
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + sim[b[j]][4]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + sim[a[i]][4]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + sim[a[i]][b[j]]);
		}
	printf("%d\n", dp[lena][lenb]);
	return 0;
}
