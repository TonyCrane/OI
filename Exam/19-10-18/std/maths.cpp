#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

const int n=10000000;
int T,dd[n+5],tot,p[n+5];
ll f[n+5];
bool vis[n+5];
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int main(){
	//freopen("maths.in","r",stdin);
	//freopen("maths.out","w",stdout);
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) p[++tot]=i,f[i]=(ll)(i-1)*i+1;
		for(int j=1;p[j]*i<=n&&j<=tot;j++)
		{
			vis[p[j]*i]=1;
			if(i%p[j]==0){
				if(f[p[j]*i]) continue;
				int t=i/p[j];
				while(t%p[j]==0) t/=p[j];
				f[p[j]*i]=f[i]*p[j]*p[j]-f[t]*p[j]+f[t];
//				break;
			}
			else f[p[j]*i]=f[i]*p[j]*p[j]-f[i]*p[j]+f[i];
		}
	}

	read(T);
	int sum=0;
	int maxx=0;
	while(T--){
		int x;
		read(x);
		cout<<f[x]<<endl;

	}

	return 0;
}
