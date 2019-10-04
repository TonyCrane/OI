#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 110
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int lk[N];
bool pd[N][N];
int n,m;
int a[N][N];
ll ans;
int front_lim[N],left_lim[N];
int vis[N],T;
bool find(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(vis[i]!=T&&pd[x][i])
        {
            vis[i]=T;
            if(!lk[i]||find(lk[i]))
            {
                lk[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
	freopen("steal.in","r",stdin);
	freopen("steal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    a[i][j]=read();
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        front_lim[j]=max(front_lim[j],a[i][j]);
        left_lim[i]=max(left_lim[i],a[i][j]);
        ans+=a[i][j];
        if(a[i][j])ans--;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i][j]&&front_lim[j]==left_lim[i])
    pd[i][j]=1;
    for(int i=1;i<=n;i++)
    {
        T++;
        find(i);
    }
    for(int i=1;i<=n;i++)
    if(left_lim[i])ans-=left_lim[i]-1;
    for(int i=1;i<=m;i++)
    if(!lk[i]&&front_lim[i])ans-=front_lim[i]-1;
    printf("%lld",ans);
}