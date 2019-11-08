//*dp[i][j]表示j状态点集的方案数*/
# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
int dp[2][1025], num[1025], sta[1025], ans[6];
void add(int &x, int y)
{
    x += y;
    if(x >= mod) x -= mod;
}
void sub(int &x, int y)
{
    x -= y;
    if(x < 0) x += mod;
}
int main()
{
    //freopen("sport.in", "r", stdin);
    //freopen("sport.out", "w", stdout);
    char c;
    int n, q, T, u, v, cnt=0;
    for(int i=0; i<1024; ++i)
    {
        num[i]= num[i>>1]+(i&1);//i的二进制有几个1
        if(~num[i]&1) sta[cnt++] = i;//sta保存偶数个1的二进制数
    }
    for(scanf("%d",&T);T;--T)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d",&n,&q);
        int now = 0;
        dp[0][0] = 1;
        while(q--)
        {
            getchar();
            c = getchar();
            scanf("%d%d",&u,&v);
            --u,--v;
            memset(ans, 0, sizeof(ans));
            int tmp = (1<<u) | (1<<v);
            if(c == '+')
            {
                for(int i=0; i<cnt&&sta[i]<(1<<n); ++i)
                {
                    int cur = sta[i];
                    dp[now^1][cur] = dp[now][cur];
                    if((cur&tmp) == tmp) add(dp[now^1][cur],dp[now][cur^tmp]);
                    add(ans[num[cur]/2],dp[now^1][cur]);
                }
            }
            else
            {
                for(int i=0; i<cnt&&sta[i]<(1<<n); ++i)
                {
                    int cur = sta[i];
                    dp[now^1][cur] = dp[now][cur];
                    if((cur&tmp) == tmp) sub(dp[now^1][cur],dp[now][cur^tmp]);
                    add(ans[num[cur]/2],dp[now^1][cur]);
                }
            }
            now ^= 1;
            for(int i=1; i<=n/2; ++i) printf("%d%c",ans[i],i==n/2?'\n':' ');
        }
    }
    return 0;
}
