#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200010
#define ll long long
#define inf 1000000000
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int mx[N<<2],mn[N<<2],sum[N<<2],L,R;
bool rev[N<<2];
int n,m,lastans;
int a[N];
void sp(int &a,int &b)
{
    a=-a,b=-b;
    swap(a,b);
}
void pushup(int x)
{
    sum[x]=sum[x<<1]+sum[x<<1|1];
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void pushdown(int x)
{
    if(rev[x])
    {
        sum[x<<1]=-sum[x<<1],sum[x<<1|1]=-sum[x<<1|1];
        sp(mn[x<<1],mx[x<<1]),sp(mn[x<<1|1],mx[x<<1|1]);
        rev[x<<1]^=1,rev[x<<1|1]^=1;
        rev[x]=0;
    }
}
void build(int x,int l,int r)
{
    if(l==r)
    {
        sum[x]=mx[x]=mn[x]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void change(int x,int l,int r,int p,int v)
{
    if(l==r)
    {
        rev[x]=0;
        sum[x]=mx[x]=mn[x]=v;
        return ;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(p<=mid)
    change(x<<1,l,mid,p,v);
    else change(x<<1|1,mid+1,r,p,v);
    pushup(x);
}
void add(int x,int l,int r,int p,int v)
{
    if(l==r)
    {
        rev[x]=0;
        sum[x]+=v;
		mx[x]+=v;
		mn[x]+=v;
        return ;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(p<=mid)
    add(x<<1,l,mid,p,v);
    else add(x<<1|1,mid+1,r,p,v);
    pushup(x);
}
void rever(int x,int l,int r)
{
    if(l>=L&&r<=R)
    {
        rev[x]^=1;
        sum[x]=-sum[x];
        sp(mx[x],mn[x]);
        return ;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(mid>=L)rever(x<<1,l,mid);
    if(mid+1<=R)rever(x<<1|1,mid+1,r);
    pushup(x);
}
int q_max(int x,int l,int r)
{
    if(l>=L&&r<=R)
    return mx[x];
    pushdown(x);
    int mid=(l+r)>>1,ret=-inf;
    if(mid>=L)ret=max(ret,q_max(x<<1,l,mid));
    if(mid+1<=R)ret=max(ret,q_max(x<<1|1,mid+1,r));
    return ret;
}
int q_min(int x,int l,int r)
{
    if(l>=L&&r<=R)
    return mn[x];
    pushdown(x);
    int mid=(l+r)>>1,ret=inf;
    if(mid>=L)ret=min(ret,q_min(x<<1,l,mid));
    if(mid+1<=R)ret=min(ret,q_min(x<<1|1,mid+1,r));
    return ret;
}
int q_sum(int x,int l,int r)
{
    if(l>=L&&r<=R)
    return sum[x];
    pushdown(x);
    int mid=(l+r)>>1,ret=0;
    if(mid>=L)ret+=q_sum(x<<1,l,mid);
    if(mid+1<=R)ret+=q_sum(x<<1|1,mid+1,r);
    return ret;
}
//---------------seg tree---------------------------
int main()
{
	freopen("bad.in","r",stdin);
	freopen("bad.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		lastans=abs(lastans);
		int opt=read();
		if(opt==1)
		{
			int x=read(),v=read();
			x=(x^lastans)%n+1;
			change(1,1,n,x,v);
		}
		else if(opt==2)
		{
			int x=read(),v=read();
			x=(x^lastans)%n+1;
			add(1,1,n,x,v);
		}
		else if(opt==3)
		{
			int l=read(),r=read();
			l=(l^lastans)%n+1,r=(r^lastans)%n+1;
			if(l>r)swap(l,r);
			L=l,R=r;
			rever(1,1,n);
		}
		else if(opt==4)
		{
			int l=read(),r=read();
			l=(l^lastans)%n+1,r=(r^lastans)%n+1;
			if(l>r)swap(l,r);
			L=l,R=r;
			lastans=q_max(1,1,n);
			printf("%d\n",lastans);
		}
		else if(opt==5)
		{
			int l=read(),r=read();
			l=(l^lastans)%n+1,r=(r^lastans)%n+1;
			if(l>r)swap(l,r);
			L=l,R=r;
			lastans=q_min(1,1,n);
			printf("%d\n",lastans);
		}
		else if(opt==6)
		{
			int l=read(),r=read();
			l=(l^lastans)%n+1,r=(r^lastans)%n+1;
			if(l>r)swap(l,r);
			L=l,R=r;
			lastans=q_sum(1,1,n);
			printf("%d\n",lastans);
		}
	}
}