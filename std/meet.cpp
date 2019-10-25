#include<bits/stdc++.h>
using namespace std;

int f[100][100];

struct rec
{
	int d,t;
	rec(){}
	rec(int a,int b)
	{
		d=a;t=b;
	}
	bool operator<(const rec &a)const
	{
		return t<a.t;
	}
}z[100];

int maxSongs(vector <int> duration, vector <int> tone, int T) {
	int n=duration.size();
	for (int a=0;a<n;a++)
		z[a]=rec(duration[a],tone[a]);
	sort(z,z+n);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	f[0][1]=z[0].d;
	for (int a=1;a<n;a++)
		for (int b=0;b<=a+1;b++)
			if (!b) f[a][b]=0;
			else
			{
				for (int c=0;c<a;c++)
					f[a][b]=min(f[a][b],f[c][b-1]+z[a].d+(b==1 ? 0 : z[a].t-z[c].t));
			}
	int ans=0;
	for (int a=0;a<n;a++)
		for (int b=1;b<=n;b++)
			if (f[a][b]<=T) ans=max(ans,b);
	return ans;
}

int main() {
	//freopen("meet.in","r",stdin);
	//freopen("meet.out","w",stdout);

	vector<int> duration;
	vector<int> tone;
	int n,T;
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
	{
		int v;
		scanf("%d",&v);
		duration.push_back(v);
	}
	for (int a=1;a<=n;a++)
	{
		int v;
		scanf("%d",&v);
		tone.push_back(v);
	}
	scanf("%d",&T);
	int answer;
	answer = maxSongs(duration, tone, T);
	printf("%d\n",answer);
	return 0;
}



