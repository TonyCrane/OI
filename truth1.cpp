#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[105];
int b[105];
int c[105];
int ans[105];
int sex[51][51][51];
int top;
int main()
{
	
	scanf("%d",&top);
	for(int i=1;i<=top;i++)
	{
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&ans[i]);
	}
	for(int k=1;k<=top;k++)
	{
		for(int i=10;i<=50;i++)
		{
			for(int j=10;j<=50;j++)
			{
				for(int h=10;h<=50;h++)
				{
					if(abs(i-a[k])+abs(j-b[k])+abs(h-c[k])==ans[k]) sex[i][j][h]++;
					if(k==top&&sex[i][j][h]==top)
					{
						printf("%d %d %d\n",i,j,h);
					}
				}
			}
		}
	}
	return 0;
}