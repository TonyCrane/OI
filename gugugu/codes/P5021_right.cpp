#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <vector>
#include <queue>
#include <set>

using namespace std;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

int n,m;

vector <int> G[50050],W[50050]; 

long long dis[50050];

bool vis[50050];

long long upper_dis=0;

inline void Get_MaxDis()
{
    /*
    树的直径的两遍bfs求法。
    做法为：任意选取一个点，然后找到距离这个点最远的点u。
    然后以u为起点，找到距离u最远的点。
    u到这个点的距离，就是树的直径。
    时间复杂度O(n) 
    */ 
    queue <int> q;
    q.push(1);
    vis[1]=true;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if (!vis[v])
            {
                vis[v]=true;
                q.push(v);
                dis[v]=dis[u]+W[u][i];
            }
        }
    }
    int st=0;
    long long maxd=0;
    for (int i=1;i<=n;i++)
        if (dis[i]>maxd)
        {
            st=i;
            maxd=dis[i];
        }
    q.push(st);
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    vis[st]=true;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if (!vis[v])
            {
                vis[v]=true;
                q.push(v);
                dis[v]=dis[u]+W[u][i];
            }
        }
    }
    maxd=0;
    for (int i=1;i<=n;i++)
        maxd=max(maxd,dis[i]);
    upper_dis=maxd;
}

/*
第一种做法
本人声明一下代码实现细节参考了Owen_codeisking大佬的做法
*/ 

namespace solve1
{
    multiset <long long> s[50050];

    long long ans=0;

    inline long long dfs(int u,int fa,long long lim)
    {
        s[u].clear();
        long long val=0;
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if (v!=fa)
            {
                val=dfs(v,u,lim)+W[u][i];
                if (val>=lim)
                    ans++;
                else
                    s[u].insert(val);
            }
        }
        long long maxd=0;
        while (!s[u].empty())
        {
            long long res=*s[u].begin(); 
            if (s[u].size()==1)
                return max(maxd,res);
            multiset <long long> :: iterator it=s[u].lower_bound(lim-res);
            if (it==s[u].begin() && s[u].count(*it)==1)
                it++;
            if (it==s[u].end())
            {
                maxd=max(maxd,res);
                s[u].erase(s[u].find(res));
            }
            else
            {
                ans++;
                s[u].erase(s[u].find(*it));
                s[u].erase(s[u].find(res));
                //相当于把两条链拼接起来形成一条链 
            }
        }
        return maxd;
    }

    long long maxd=0;

    inline bool check(long long lim)
    {
        ans=0;
        dfs(1,0,lim);
        return ans>=m;
    }

    inline long long main()
    {
        long long left=1,right=upper_dis,mid;
        while (left<right)
        {
            mid=(left+right+1)>>1;
            if (check(mid))
                left=mid;
            else
                right=mid-1;
        }
        return left;
    }
}

/*
本题的第二种做法
本质上和第一种做法是类似的
只不过代码实现难度更低，
内存个人认为应当比第一篇好一些 
啊还有这个做法是我们老师上课所讲的
希望不会再有什么奇怪的重复了QAQ 
*/ 

namespace solve2
{
    inline long long dfs(int u,int fa,long long &len,long long lim)
    {
        int ans=0;
        multiset <long long> s;
		printf("size: %d\n", G[u].size());
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
			printf("v: %d\n", v);
            if (v!=fa)
            {
                long long res;
                ans+=dfs(v,u,res,lim);
                res+=W[u][i];
                if (res>=lim)
                    ans++;
                else
                    s.insert(res);
            }
        }
        len=0;
        while (!s.empty())
        {
            long long res=*s.begin();
            s.erase(s.begin());
            multiset <long long> :: iterator it=s.lower_bound(lim-res);
            if (it!=s.end())
            {
                //如果找到了就说明可以拼接起来
                //否则就要去更新最长长度。 
                s.erase(it);
                ans++;
            }
            else
                len=max(len,res);
        }
        return ans;
    }

    inline long long main()
    {
        long long left=0,right=upper_dis+1,mid;
        while (right-left>1)
        {
            mid=(left+right)>>1;
            long long res;
			printf("dfs: %lld\n", dfs(1, 0, res, mid));
            if (dfs(1,0,res,mid)>=m)
                left=mid;
            else
                right=mid;
        }
        return left;
    }
}

int main()
{
    n=read(),m=read();
    for (int i=1;i<n;i++)
    {
        int u=read(),v=read(),d=read();
        G[u].push_back(v);
        G[v].push_back(u);
        W[u].push_back(d);
        W[v].push_back(d);
    }
    Get_MaxDis();
	printf("upper_dis: %lld\n", upper_dis);
    cout << solve2::main() << endl;
    return 0;
}
