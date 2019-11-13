#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100005
#define M 100005
using namespace std;
int ai[N],fi[M]={0},gi[M],ans[N]={0};
bool di[N]={false};
int main(){
    //freopen("coin.in","r",stdin);
    //freopen("coin.out","w",stdout);
    
    int n,x,i,j,k,cnt=0;
    scanf("%d%d",&n,&x);
    for (i=1;i<=n;++i){
        scanf("%d",&ai[i]);
        di[ai[i]]=true;
    }
    fi[0]=1;
    for (i=1;i<=n;++i)
        for (j=x;j>=ai[i];--j)
            fi[j]+=fi[j-ai[i]];
    for (i=1;i<N;++i){
        if (!di[i]) continue;
        memset(gi,0,sizeof(gi));
        for (j=0;j<i;++j)
            gi[j]=fi[j];
        for (;j<=x;++j)
            gi[j]=fi[j]-gi[j-i];
        if (!gi[x]) ans[++ans[0]]=i;
    }
    printf("%d\n",ans[0]);
    for (i=1;i<=ans[0];++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
