#include<bits/stdc++.h>
using namespace std;

int N, a[5001], b[5], e[5], num = 0;
int day[12]={
31,28,31,30,31,30,31,31,30,31,31,30};
unsigned long long t = 0;

bool rn(int y)
{

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	    return false;
	else return true;
}
				
int main()
{				
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>a[i];
	for (int i = 1; i >= N - 1; ++i)
		for (int j = 0; j < N - i; ++j)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	scanf("%d-%d-%d-%d:%d", &b[0], &b[1], &b[2], &b[3], &b[4]);
	scanf("%d-%d-%d-%d:%d", &e[0], &e[1], &e[2], &e[3], &e[4]);
	for(int i = b[0]; i < e[0]; i++)
		if(rn(i)) t -= 366;
		else t -= 365;
	for(int i = 0; i < b[1]; i++) t += day[i];
	for(int i = 0; i < e[1]; i++) t -= day[i];
	if(rn(b[0]) && b[1] > 2) t++;
	if(rn(e[0]) && e[1] > 2) t--;
	t += b[2];
	t -= e[2];
	t *= 1440;
	t += 60 * b[3] + b[4];
	t -= 60 * e[3] + e[4];
	t *= -1;
	for (int i = 0; i < N; ++i)		
	{
		if (t >= a[i])
		{
			t -= a[i];
			num++;
		}
	}
	cout<<num<<endl;
    return 0;
}
