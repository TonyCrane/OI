#include<cstdio>
#include<utility>
using namespace std;

#define rep(i,__l,__r) for(int i=__l,i##_end_=__r;i<=i##_end_;++i)
#define fep(i,__l,__r) for(int i=__l,i##_end_=__r;i>=i##_end_;--i)
#define writc(a,b) fwrit(a),putchar(b)
#define mp(a,b) make_pair(a,b)
#define ft first
#define sd second
#define LL long long
// #define FILEOI

typedef pair<int,int> pii;

#define cg (c=getchar())
template<class T>inline void qread(T& x){
    char c;bool f=0;
    while(cg<'0'||'9'<c)if(c=='-')f=1;
    for(x=(c^48);'0'<=cg&&c<='9';x=(x<<1)+(x<<3)+(c^48));
    if(f)x=-x;
}
inline int qread(){
    int x=0;char c;bool f=0;
    while(cg<'0'||'9'<c)if(c=='-')f=-1;
    for(x=(c^48);'0'<=cg&&c<='9';x=(x<<1)+(x<<3)+(c^48));
    return f?-x:x;
}
#undef cg
template<class T,class... Args>inline void qread(T& x,Args&... args){qread(x),qread(args...);}
template<class T>inline T Max(const T x,const T y){return x>y?x:y;}
template<class T>inline T Min(const T x,const T y){return x<y?x:y;}
template<class T>inline T fab(const T x){return x>0?x:-x;}
inline void getInv(int inv[],const int lim,const int MOD){
    inv[0]=inv[1]=1;for(int i=2;i<=lim;++i)inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
}
template<class T>void fwrit(const T x){
    if(x<0)return (void)(putchar('-'),fwrit(-x));
    if(x>9)fwrit(x/10);putchar(x%10^48);
}

const int MAXN=2000;

struct edge{
    int to,nxt;
    edge(){}
    edge(const int T,const int N):to(T),nxt(N){}
}e[(MAXN<<1)+5];
int tail[MAXN+5],ecnt,in[MAXN+5],maxin,tcnt;
pii t[MAXN+5];
inline void add_edge(const int u,const int v){
    ++in[u],++in[v];//更改点的入度
    e[++ecnt]=edge(v,tail[u]);tail[u]=ecnt;
    e[++ecnt]=edge(u,tail[v]);tail[v]=ecnt;

    maxin=Max(maxin,Max(in[u],in[v]));//特判菊花图
    t[++tcnt]=mp(u,v);//记录一条边连接的两个点
}

int N,a[MAXN+5],ans[MAXN+5];
//a[i] : 点 i 的数字是多少
//ans[i] : 记录答案

inline void init(){
    qread(N);

    //清空图
    ecnt=0,tcnt=0,maxin=0;
    rep(i,1,N)tail[i]=0,in[i]=0,ans[i]=N-i+1;

    //输入
    rep(i,1,N)a[qread()]=i;
    rep(i,1,N-1)add_edge(qread(),qread());
    /*
    rep(i,1,N)writc(a[i],' ');
    putchar('\n');
    */
}

int pre[MAXN+5];
inline void buildSet(){rep(i,1,N)pre[i]=i;}
int findSet(const int u){return u==pre[u]?u:pre[u]=findSet(pre[u]);}
inline void unionSet(const int u,const int v){return (void)(pre[findSet(u)]=findSet(v));}

bool vis[MAXN+5];
int tmp[MAXN+5],pt[MAXN+5];

inline void work(){//处理菊花图
    buildSet();
    rep(i,1,N)tmp[a[i]]=i,vis[i]=0;
    rep(i,1,N-1){
        rep(j,1,N)if(!vis[j]&&findSet(tmp[i])!=findSet(j)){
            vis[j]=true,pt[tmp[i]]=j;
            unionSet(tmp[i],j);
            break;
        }
    }
    rep(i,1,N-1)writc(pt[tmp[i]],' ');
    rep(i,1,N)if(!vis[i]){
        writc(i,'\n');
        break;
    }
}

int mir[MAXN+5];
void dfs(const int);
inline void getDfs(){
    rep(i,1,N)vis[i]=0;
    dfs(1);
    rep(i,1,N-1)writc(ans[i],' ');
    writc(ans[N],'\n');
}
inline void chk(){
    rep(i,1,N)mir[a[i]]=i;
    rep(i,1,N){
        if(mir[i]<ans[i]){
            rep(j,1,N)ans[j]=mir[j];
            break;
        }
        if(mir[i]>ans[i])break;
    }
    return;
}
void dfs(const int p){
    if(p==N)return chk();
    rep(i,1,N-1)if(!vis[i]){
        swap(a[t[i].ft],a[t[i].sd]);vis[i]=true;
        dfs(p+1);
        swap(a[t[i].ft],a[t[i].sd]);vis[i]=false;
    }
}

int lt[MAXN+5],lcnt;
short int mark[MAXN+5];//标记 : 0-无标记 ; 1-左先右后 ; 2-左后右先
inline void getlist(const int u,const int pre){
    lt[pt[u]=++lcnt]=u;
    for(int i=tail[u],v;i;i=e[i].nxt)if((v=e[i].to)!=pre)
        getlist(v,u);
}
inline bool chkl(const int p1,const int p2){
    if(mark[pt[p1]]==1)return false;

    rep(i,pt[p1]+1,pt[p2]-1)if(mark[i]==2)return false;

    if(mark[pt[p2]]==1)return false;

    return true;
}
inline void getMarkl(const int p1,const int p2){//当 pt[p1]<=pt[p2] 时
    if(pt[p1]!=1&&pt[p1]!=N)mark[pt[p1]]=2;

    rep(i,pt[p1]+1,pt[p2]-1)mark[i]=1;

    if(pt[p2]!=1&&pt[p2]!=N)mark[pt[p2]]=2;
}
inline bool chkr(const int p1,const int p2){//当 pt[p1]>pt[p2] 时
    if(mark[pt[p1]]==2)return false;

    fep(i,pt[p1]-1,pt[p2]+1)if(mark[i]==1)return false;

    if(mark[pt[p2]]==2)return false;

    return true;
}
inline void getMarkr(const int p1,const int p2){
    if(pt[p1]!=1&&pt[p1]!=N)mark[pt[p1]]=1;

    fep(i,pt[p1]-1,pt[p2]+1)mark[i]=2;

    if(pt[p2]!=1&&pt[p2]!=N)mark[pt[p2]]=1;
}
inline void workList(){//解决单链
    lcnt=0;
    rep(i,1,N)if(in[i]==1){//压到数组上面
        getlist(i,0);
        break;
    }
    
    printf("this is the list:");
    rep(i,1,N)writc(lt[i],' ');
    putchar('\n');
    printf("this is pt arr:");
    rep(i,1,N)writc(pt[i],' ');
    putchar('\n');
    

    rep(i,1,N)vis[i]=false,mir[a[i]]=i,mark[i]=0;

    printf("this is the mir arr:");
    for (int i = 1; i <= N; ++i) printf("%d ", mir[i]);
    putchar('\n');
    rep(i,1,N)rep(j,1,N)if(!vis[j]&&pt[j]!=pt[mir[i]]){
        //目标位置不能和本来的位置重合并且目标位置还没有被其他优先级更高的数占有
        printf("Now the number is %d, the goal position is %d\n",i,j);
        int p1=mir[i],p2=j;bool flg=false;
        if(pt[p1]<=pt[p2]){//如果这个数是往左边走
            if(chkl(p1,p2))
                getMarkl(p1,p2),flg=true;
        }
        else{//反之
            if(chkr(p1,p2))
                getMarkr(p1,p2),flg=true;
        }
        if(flg){//记录答案
            ans[i]=j,vis[j]=true;
            break;
        }
    }
    rep(i,1,N-1)writc(ans[i],' ');//输出答案
    writc(ans[N],'\n');
}

int T;

signed main(){
#ifdef FILEOI
    freopen("rdata.out","r",stdin);
    freopen("file.out","w",stdout);
#endif
    qread(T);
    while(T--){
        init();
        // if(N<=10)getDfs();
        // else if(maxin==N-1)work();
        // else if(maxin==2)workList();
        // else puts("gugugu~~~");
        workList();
    }
    return 0;
}