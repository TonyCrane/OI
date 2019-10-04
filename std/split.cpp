#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define mod 1000000007
using namespace std;
typedef long long ll;
inline ll read() 
{ 
    ll x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
ll n;
struct jz
{
    ll node[11][11];
}ans,mid;
jz cheng(jz a,jz b)
{
    jz temp;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
       {
        temp.node[i][j]=0;
        for(int k=0;k<11;k++)
         {
          temp.node[i][j]=(temp.node[i][j]%mod+(a.node[i][k]*b.node[k][j])%mod+mod)%mod;
         }
        }
     }
     return temp;
}
void csh()
{
	for(int i=0;i<11;i++)
	for(int j=0;j<11;j++)
	ans.node[i][j]=0;
	for(int i=0;i<11;i++)
	ans.node[i][i]=1;
    for(int i=0;i<11;i++)
	for(int j=0;j<11;j++)
	mid.node[i][j]=0;
    mid.node[0][0]=mid.node[0][1]=1,mid.node[0][10]=-1;
    for(int i=1;i<11;i++)
    mid.node[i][i-1]=1;
}
inline ll pw(ll b)
{
    csh();
    while(b>0)
    {
        if(b&1)ans=cheng(ans,mid);
        mid=cheng(mid,mid);
        b>>=1;
    }
    return ans.node[0][1];
}
int main()
{
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	int T=read();
	while(T--)
	{	
		n=read()+1;
	    printf("%lld\n",(pw(n)+pw(n-11))%mod);
	}
    
}