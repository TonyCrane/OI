#include<cstdio>
#include<algorithm>
using namespace std;
inline int hsh(int x,int y)
{
	return x*2-y;
}
struct dsu
{
	int fat[22000],siz[22000];
	int stp,sta[2200000][2];
	inline void init(int x)
	{
		stp=0;
		for (int i=1;i<=x*2;i++)
		{
			siz[i]=1;
			fat[i]=i;
		}
	}
	inline int fnd(int x)
	{
		if(fat[x]==x)return x;
		return fnd(fat[x]);
	}
	inline void back()
	{
		if(sta[stp][0]==-1)
		{
			stp--;
			return;
		}
		int x=sta[stp][1];
		int y=sta[stp][0];
		siz[y]-=siz[x];
		fat[x]=x;
		stp--;
	}
	inline void uin(int x,int y)
	{
		x=fnd(x);
		y=fnd(y);
		if(x==y)
		{
			stp++;
			sta[stp][0]=-1;
			return;
		}
		if(siz[x]>siz[y])swap(x,y);
		fat[x]=y;
		siz[y]+=siz[x];
		stp++;
		sta[stp][0]=y;
		sta[stp][1]=x;
	}
	inline bool together(int x,int y)
	{
		return fnd(x)==fnd(y);
	}
}sgt;
int n,m;
int vis[1200000],fr[1200000],last;
int x1,x2,op,num;
inline void print(int x)
{
	if(x)puts("NO");
	else puts("YES");
}
int main()
{
	//freopen("graph.in","r",stdin);
	//freopen("graph.out","w",stdout);
	scanf("%d %d",&n,&m);
	sgt.init(n);
	for (int cas=1;cas<=m;cas++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d %d",&x1,&x2);
			fr[cas]=last;
			if(vis[last]==1)
			{
				vis[cas]=1;
			}
			else if(sgt.together(hsh(x1,0),hsh(x2,0))||sgt.together(hsh(x1,1),hsh(x2,1)))
			{
				vis[cas]=1;
			}
			else
			{
				sgt.uin(hsh(x1,0),hsh(x2,1));
				sgt.uin(hsh(x1,1),hsh(x2,0));
			}
			last=cas;
			print(vis[last]);
		}
		else
		{
			if(vis[last]==1);
			else
			{
				sgt.back();
				sgt.back();
			}
			last=fr[last];
			print(vis[last]);
		}
	}
	return 0;
}
