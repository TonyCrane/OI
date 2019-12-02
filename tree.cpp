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
    /*
    printf("this is the list:");
    rep(i,1,N)writc(lt[i],' ');
    putchar('\n');
    printf("this is pt arr:");
    rep(i,1,N)writc(pt[i],' ');
    putchar('\n');
    */

    rep(i,1,N)vis[i]=false,mir[a[i]]=i,mark[i]=0;

    rep(i,1,N)rep(j,1,N)if(!vis[j]&&pt[j]!=pt[mir[i]]){
        //目标位置不能和本来的位置重合并且目标位置还没有被其他优先级更高的数占有
        // printf("Now the number is %d, the goal position is %d\n",i,j);
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