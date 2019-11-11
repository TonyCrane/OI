#include<bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
const int N = 2e5 +11;
int T,n;
LL cnt[N];
LL m,a[N],b[N],q[N],c[N];
int add(int k,LL d,LL *t){
    for(;k<=n;k+=k&-k)t[k]+=d;
}
LL g(int k,LL *t){
    if(k<0)return 0;
    LL A=0;
    for(;k;k-=k&-k)A+=t[k];
    return A;
}
int main(){
	// freopen("gohome.in", "r", stdin);
	// freopen("gohome.out", "w", stdout);
    ios::sync_with_stdio(false);
    for(cin>>T;T;T--){
        memset(q,0,sizeof q);
        memset(cnt,0,sizeof cnt);
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
        sort(b+1,b+1+n);
        int len =unique(b+1,b+1+n)-b-1;
        for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+1+len,a[i])-b;
        for(int i=1;i<=n;i++){
            int l=0,r=n,ok=0;
            LL MAX=g(n,q);
            while(l<=r){
                int mid=l+r>>1;
                if(b[a[i]]+g(mid,q)<=m){
                    ok=mid;
                    l=mid+1;
                }else r=mid-1;
            }
            ok++;
            if(ok>n){
                add(a[i],b[a[i]],q);
                add(a[i],1,cnt);
                cout<<0<<' ';
            }else{
                int now=g(ok,cnt)-g(ok-1,cnt);//ok 
                int l=0,r=now,ans=0;
                LL need=g(ok-1,q);
                while(l<=r){
                    LL mid=l+r>>1;
                    if(mid*b[ok]+b[a[i]]+need<=m){
                        ans=mid;
                        l=mid+1;
                    }else r=mid-1;
                }
                cout<<g(n,cnt)-g(ok-1,cnt)-ans<<' ';
                add(a[i],b[a[i]],q);
                add(a[i],1,cnt);                            
            }
        }
        cout<<endl;
    }
    return 0;
}
