#include<bits/stdc++.h>
using namespace std;

string a[21];

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
		cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) cout<<a[i];
	return 0;
}
