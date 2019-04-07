#include<bits/stdc++.h>
using namespace std;

int w, l, cnt;
char ch;
string str;

int main()
{
	while (cin >> ch && ch != 'E')
	{
		if (ch == 'W') {w++; str += ch;}
		if (ch == 'L') {l++; str += ch;}
		if ((w >= 11 || l >= 11) && (w - l >= 2 || l - w >= 2))
		{
			printf("%d:%d\n", w, l);
			w = 0; l = 0;
		}
		cnt++;
	}
	printf("%d:%d\n\n", w, l);
	w = 0; l = 0;

	for (int i = 0; i < cnt; ++i)
	{
		if (str[i] == 'W') w++;
		if (str[i] == 'L') l++;
		if ((w >= 21 || l >= 21) && (w - l >= 2 || l - w >= 2))
		{
			printf("%d:%d\n", w, l);
			w = 0; l = 0;
		}
	}
	printf("%d:%d\n", w, l);
	return 0;
}
