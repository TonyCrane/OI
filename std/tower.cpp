#include<bits/stdc++.h>
#define N 100010
#define INF 0x3f3f3f3f
#define LL long long
#define pb push_back
#define cl clear
#define si size
#define lb lowwer_bound
#define eps 1e-8
const LL mod=1e9+7;
using namespace std;
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> >q[5];

int a[N][5],b[N][5],v[5];
namespace IO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
};
 
int main()
{
    //freopen("tower.in", "r", stdin);
    //freopen("tower.out", "w", stdout);

    int T;
    IO::read(T);
    while(T--)
    {
        int n,m;
        IO::read(n);IO::read(m);
        for(int i=0;i<m;i++) while(!q[i].empty()) q[i].pop();
        for (int i=0;i<m;i++) IO::read(v[i]);
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<m;j++) IO::read(a[i][j]);
            for (int j=0;j<m;j++) IO::read(b[i][j]);
            q[0].push(P(a[i][0],i));
        }
        int p=0,ans=0;
        while(1)
        {
            for (int i=0;i<m-1;i++)
            {
                while(!q[i].empty() && q[i].top().first<=v[i])
                {
                    int x=q[i].top().second; q[i].pop();
                    q[i+1].push(P(a[x][i+1],x));
                }
            }
            while (!q[m-1].empty() && q[m-1].top().first<=v[m-1])
            {
                ans++;
                int x=q[m-1].top().second; q[m-1].pop();
                for (int i=0;i<m;i++) v[i]+=b[x][i];
            }
            if (p==ans) break;
            p=ans;
        }
        cout<<ans<<endl;cout<<v[0];
        for (int i=1;i<m;i++) cout<<' '<<v[i];
        cout<<endl;
    }
    return 0;
}
