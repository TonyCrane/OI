#include<bits/stdc++.h>
using namespace std;

string mid, aft;

void func(string mids, string afts)
{
	if (mids.size() > 0)
	{
		char ch = afts[afts.size() - 1];
		cout << ch;
		int k = mids.find(ch);
		func(mids.substr(0, k), afts.substr(0, k));
		func(mids.substr(k + 1), afts.substr(k, mids.size() - k - 1));
	}
}

int main()
{
	cin >> mid >> aft;
	func(mid, aft);
	printf("\n");
	return 0;
}
