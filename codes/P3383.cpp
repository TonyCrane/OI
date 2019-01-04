#include<bits/stdc++.h>
using namespace std;

const int N=10000010;

int prime[N],cnt;
bool vis[N];
int m,n,tmp;

void getprime(int n)
{
    vis[1]=true;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++)
        {
            int v=i*prime[j];
            if(v>n) break;
            vis[v]=true;
        }
    }
}

int main()
{
    scanf("%d",&n);
    getprime(n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&tmp);
        if(vis[tmp]) puts("No");
        else puts("Yes");
    }
}
