#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int mod=1000000007;
stack<int> s;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
long long a[15][15],b[15][15],n,c[15],d[15][15],ans[15];
int main()
{
	scanf("%lld",&n);
	if(n==1)
	{
		return 0;
	}
	else if(n==2)
	{
		return 0;
	}
	n--;

	c[1]=1;
	for(int i=1;i<=9;i++)
	{
		a[i][i-1]=b[i][i-1]=1;
	}
	for(int i=1;i<=9;i++)
	a[0][i]=b[0][i]=1;
	while(n>1)
	{
		
		if(n%2==0)
		{
			s.push(2);
			n=n/2;
		}
		else
		{
			s.push(1);
			n--;
		}
	}
	while(!s.empty())
	{
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			d[i][j]=0;
		}
		if(s.top()==1)
		{
			s.pop();
			for(int i=0;i<=9;i++)
			{
				for(int j=0;j<=9;j++)
				{
					for(int x=0;x<=9;x++)
					{
						d[i][j]+=a[i][x]*b[x][j];
						d[i][j]%=mod;
					}
				}
			}
			for(int i=0;i<=9;i++)
			{
				for(int j=0;j<=9;j++)
				a[i][j]=d[i][j];
			}
		}
		else if(s.top()==2)
		{
			s.pop();
			for(int i=0;i<=9;i++)
			{
				for(int j=0;j<=9;j++)
				{
					for(int x=0;x<=9;x++)
					{
	  					d[i][j]+=a[x][j]*a[i][x];
						d[i][j]%=mod;
					}
				}
			}
			for(int i=0;i<=9;i++)
			{
				for(int j=0;j<=9;j++)
				a[i][j]=d[i][j];
			}
		}
	}
	for(int i=0;i<=9;i++)
	{
		for(int x=0;x<=9;x++)
		{
			ans[i]=(ans[i]+c[x]*a[i][x])%mod;
		}
	}
	long long sum=0;
	for(int i=0;i<=9;i++)
	sum=(sum+ans[i])%mod;
	cout<<sum;
}
/*
这个std是大佬yycc的矩阵qwq
并没有处理多组数据 仅供参考 
*/