#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<set>
#define ll long long
using namespace std;

int T,n,m,l,r,pre[100005],ans[100005];
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d",&T);
    while(T--){
        memset(pre,0,sizeof(pre));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            pre[i]=i;
        for(int i=0;i<m;i++){
            scanf("%d %d",&l,&r);
            pre[r]=min(pre[r],l);
        }

        for(int i=n-1;i>=1;i--)
            pre[i]=min(pre[i],pre[i+1]);
        int pl=1;
        set<int>s;
        for(int i=1;i<=n;i++)
            s.insert(i);
        for(int i=1;i<=n;i++){
            while(pl<pre[i]){
                s.insert(ans[pl]);
                pl++;
            }
            ans[i]=*s.begin();
            s.erase(ans[i]);
        }

       printf("%d",ans[1]);
       for(int i=2;i<=n;i++)
            printf(" %d",ans[i]);
        cout<< endl;
    }
    return 0;
}
