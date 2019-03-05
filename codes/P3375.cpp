/*************************************************************
 *  > File Name        : P3375.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年03月04日 星期一 12时52分38秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

char s1[1000010], s2[1000010];
int nxt[1000010], l1, l2;

void pre()
{
	nxt[1] = 0;
	int j = 0;
	for (int i = 1; i < l2; ++i)
	{
		while (j > 0 && s2[j + 1] != s2[i + 1]) j = nxt[j];
		if (s2[j + 1] == s2[i + 1]) j++;
		nxt[i + 1] = j;
	}
}

void kmp()
{
	int j = 0;
	for (int i = 0; i < l1; ++i)
	{
		while (j > 0 && s2[j + 1] != s1[i + 1]) j = nxt[j];
		if (s2[j + 1] == s1[i + 1]) j++;
		if (j == l2)
		{
			printf("%d\n", i - l2 + 2);
			j = nxt[j];
		}
	}
}

int main()
{
	cin >> s1 + 1;
	cin >> s2 + 1;
	l1 = strlen(s1 + 1);
	l2 = strlen(s2 + 1);
	pre();
	kmp();
	for (int i = 1; i <= l2; ++i)
		printf("%d ", nxt[i]);
	return 0;
}
