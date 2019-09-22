#include
#include
#include
#define LL long long
using namespace std;
int n,m;
LL s[500010],w[500010],A,dx,S,h;
int _18520(){
    scanf("%d%d",&n,&m); A=0;
    for(int i=1;i<=n;++i) scanf("%lld",s+i);
    for(int i=1,z=m/n;i<=z;++i){
        dx=1ll<<60; S=(n*i+1ll)*(LL)n*i>>1;
        for(int j=1;j<=n;++j){
            s[j]-=i*n-n+j;
            dx=min(dx,s[j]);
        }
        if(dx<0) break;
        h=min((LL)i,dx/(m-i*n));
        S+=n*h*(m-i*n); dx=h*(m-i*n);
        for(int j=1;j<=n;++j) w[j]=s[j]-dx;
        dx=m-i*n;
        for(int j=i-h;j>=i-h-1&&j;--j)
            for(int k=n;k;--k){
                dx=min(w[k],dx);
                S+=dx; w[k]-=dx;
                if(dx==0) break;
            }
        A=max(A,S);
    }
    printf("%lld\n",A);
}
int main(){
    freopen("compete.in","r",stdin);
    freopen("compete.out","w",stdout); 
    int T; for(scanf("%d",&T);T--;_18520());
}