#include<bits/stdc++.h>
using namespace std;

stack<int> sta;
char ch;
int s, x, y;

int main()
{
	scanf("%c", &ch);
	while (ch != '@')
	{
		if (ch == '+')
		{
			x = sta.top(); sta.pop();
			y = sta.top(); sta.pop();
			sta.push(x + y);
		}
		else if (ch == '-')
		{
			x = sta.top(); sta.pop();
			y = sta.top(); sta.pop();
			sta.push(y - x);
		}
		else if (ch == '*')
		{
			x = sta.top(); sta.pop();
			y = sta.top(); sta.pop();
			sta.push(x * y);
		}
		else if (ch == '/')
		{
			x = sta.top(); sta.pop();
			y = sta.top(); sta.pop();
			sta.push(y / x);
		}
		else if (ch == '.')
		{
			sta.push(s);
			s = 0;
		}
		else
		{
			s = s * 10 + ch - '0';
		}
		scanf("%c", &ch);
	}
	printf("%d\n", sta.top());
	return 0;
}
