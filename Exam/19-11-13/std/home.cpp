#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#define pa pair<int,int>
#define inf 1000000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,n,m,cnt,ans,mid;
int last[105],q[105],d[105];
bool mark[105],con[105];
struct data{int to,next,v;}e[200005];
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
}
bool dfs(int x)
{
	mark[x]=1;
	for(int i=last[x];i;i=e[i].next)
		if(d[x]+e[i].v+mid<d[e[i].to]&&con[e[i].to])
		{
			if(mark[e[i].to])return 1;
			d[e[i].to]=d[x]+e[i].v+mid;
			if(dfs(e[i].to))return 1;
		}
	mark[x]=0;
	return 0;
}
void spfa()
{
	for(int i=1;i<=n;i++)d[i]=inf;
	int head=0,tail=1;
	q[0]=1;mark[1]=1;d[1]=0;
	while(head!=tail)
	{
		int now=q[head];head++;if(head==100)head=0;
		for(int i=last[now];i;i=e[i].next)
			if(d[now]+e[i].v+mid<d[e[i].to]&&con[e[i].to])
			{
				d[e[i].to]=d[now]+e[i].v+mid;
				if(!mark[e[i].to])
				{
					mark[e[i].to]=1;
					q[tail]=e[i].to;tail++;
					if(tail==100)tail=0;
				}
			}
		mark[now]=0;
	}
}
void dfscon(int x)
{
	mark[x]=1;
	for(int i=last[x];i;i=e[i].next)
		if(!mark[e[i].to])
			dfscon(e[i].to);
}
bool jud()
{
	for(int i=1;i<=n;i++)
		if(con[i])
		{
			for(int j=1;j<=n;j++)d[j]=inf;
			memset(mark,0,sizeof(mark));
			if(dfs(i))return 0;
		}
	spfa();
	if(d[n]>=0&&d[n]!=inf)return 1;
	return 0;
}
int main()
{
	//freopen("home.in","r",stdin);
	//freopen("home.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(con,1,sizeof(con));
		memset(last,0,sizeof(last));
		cnt=0;ans=-1;
		n=read();m=read();
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read(),w=read();
			insert(u,v,w);
		}
		memset(mark,0,sizeof(mark));
		dfscon(1);
		for(int i=1;i<=n;i++)if(!mark[i])con[i]=0;
		for(int i=1;i<=n;i++)
			if(con[i])
			{
				memset(mark,0,sizeof(mark));
				dfscon(i);
				if(!mark[n])con[i]=0;
			}
		int l=-100000,r=100000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(jud())ans=d[n],r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
