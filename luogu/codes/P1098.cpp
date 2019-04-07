#include<bits/stdc++.h>
using namespace std;

int p1, p2, p3, i; 
char ch[500], before, after, now, ans;

int main()
{
	scanf("%d %d %d", &p1, &p2, &p3);
	scanf("%s", ch);
	while (ch[i])
	{
		before = ch[i - 1];
		after  = ch[i + 1];
		now    = ch[i];
		if (now == '-' && after > before && ((after <= '9' && before >= '0') || (after <= 'z' && before >= 'a')))
		{
			for (char j = (p3 == 1)? before + 1 : after - 1; (p3 == 1)? j < after : j > before; (p3 == 1)? j++ : j--)
			{
				ans = j;
				if (p1 == 2)
					ans = (ans >= 'a')? ans - 32 : ans;
				else if (p1 == 3) ans = '*';
				for (int k = 1; k <= p2; ++k)
					printf("%c", ans);
			}
		}
		else
			printf("%c", now);
		i++;
	}
	return 0;
}
