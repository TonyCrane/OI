#include<bits/stdc++.h>
using namespace std;

stack<bool> sta;
char ch;

int main()
{
	scanf("%c", &ch);
	if (ch == ')')
	{
		printf("NO\n");
		return 0;
	}
	while (ch != '@')
	{
		if (ch == '(') sta.push(true);
		if (ch == ')') 
		{
			if (sta.empty())
			{
				printf("NO\n");
				return 0;
			}
			sta.pop(); 
		}
		scanf("%c", &ch);
	}
	if (sta.empty()) printf("YES\n");
	else printf("NO\n");
	return 0;
} 
