#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
double a[105];
double b[105];
double c[105];
double ans[105];
int n;
double sex[105][105][105];
double minn=130471834;
int ans1,ans2,ans3;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf %lf %lf",&a[i],&b[i],&c[i],&ans[i]);
	}
	for(int k=1;k<=n;k++)
	{
		for(double i=50;i<=100;i++)
		{
			for(double j=50;j<=100;j++)
			{
				for(double h=50;h<=100;h++)
				{
					sex[(int)i][(int)j][(int)h]+=fabs(ans[k]-sqrt((i-a[k])*(i-a[k])+(j-b[k])*(j-b[k])+(h-c[k])*(h-c[k])));
					if(k==n)
					{
						if(sex[(int)i][(int)j][(int)h]<minn)
						{
							ans1=i;
							ans2=j;
							ans3=h;
							minn=sex[(int)i][(int)j][(int)h];
						}
					}
				}
			}
		}
	}
	printf("%d %d %d",ans1,ans2,ans3);
	return 0;
}