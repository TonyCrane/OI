#include<bits/stdc++.h>
using namespace std;

int M, S, C, a[300], b[300], ans;

bool cmp(int c, int d)
{
	return a > b;
}

int main()
{
	cin>>M>>S>>C;
	for (int i = 1; i <= C; ++i) cin>>a[i];
	sort(a + 1, a + 1 + C);
	for (int i = 1; i < C; ++i) b[i] = a[i + 1] - a[i] - 1;
	sort(b + 1, b + C, cmp);
	ans = a[C] - a[1] + 1;
	for (int i = 1; i < M && i < N; ++i) ans -= b[i];
	cout<<ans;
	return 0;
}
