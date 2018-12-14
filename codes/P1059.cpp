#include<bits/stdc++.h>
using namespace std;

int main()
{
	int b[1001], n, m = 0, x;
	memset(b, 0, sizeof(b));
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		if (b[x] == 0) m++;
		b[x]++;
	}
	cout << m << endl;
	for (int i = 0; i <= 1000; ++i)
		if (b[i] > 0) cout << i << " ";
	cout << endl;
	return 0;
}
