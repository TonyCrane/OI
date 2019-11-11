#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn=2e5+5;
ll a[maxn],f[maxn];
 
int bit[maxn*2+100];
void update(int x,int d){
    for(int i=x;i>0;i-=i&-i) bit[i]=max(bit[i],d);
}
int querysuf(int x,int B){
    int ret=-1e9;
    for(int i=x;i<B;i+=i&-i) ret=max(bit[i],ret);
    return ret;
}
void remove(int x,int B){
    for(int i=x;i<B;i+=i&-i) bit[i]=-1e9;
    for(int i=x;i>0;i-=i&-i) bit[i]=-1e9;
}
 
vector<ll> disc;
int getid(ll x){return lower_bound(disc.begin(),disc.end(),x)-disc.begin()+1;}
 
bool check(ll ans,int n,int k){// sum<=ans
    disc.clear();
    for(int i=1;i<=n;i++) {
        disc.push_back(a[i]);
        disc.push_back(a[i]-ans);
    }
    disc.push_back(0);
    sort(disc.begin(),disc.end());
    disc.erase(unique(disc.begin(),disc.end()),disc.end());
 
    for(int i=1;i<=disc.size();i++) remove(i,disc.size());
    f[0]=0;
    update(getid(0),f[0]);
    for(int i=1;i<=n;i++) {
        f[i]=querysuf(getid(a[i]-ans),disc.size()+1)+1;
        update(getid(a[i]),f[i]);
        if(f[i]>=k) return true;
    }
    return false;
}
 
int main(){
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int T; scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) {
            scanf("%lld",a+i);
            a[i]+=a[i-1];
        }
        ll l=-1e9*1e6,r=1e9*1e6;
        while(l+1<r){//  ans -> ( ]
            ll mid=(l+r)/2;//
            if(check(mid,n,k)) r=mid;//
            else l=mid;
        }
        printf("%lld\n",r);
    }
    return 0;
}