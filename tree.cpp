#include <bits/stdc++.h>
using namespace std;
const int N = 4100;
const int s = 4100; // 用 s + 编号u 代表u的起始
const int t = 6100; // 用 t + 编号u 代表u的终止
int T, n, p[N], nxt[N<<1], h[N], to[N<<1], cnt;
int ne[N<<1], la[N<<1], min_num;
int f[N<<1], siz[N<<1], in[N]; // siz[]维护删了几条边 in[]维护共有几条边
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
inline void add_edge(int u, int v) {
    ++cnt; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v; siz[cnt] = 1;
} // 如果是边 siz为1
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
} // 用并查集维护链表是否成环
bool check(int a, int b, int u) {
    if(find(a) == find(b)) return false; // 成环了不行
    if(ne[a] || la[b]) return false; // a有后继或者b有前驱不行
    int fa = find(a), fb = find(b), fs = find(s+u), ft = find(t+u);
    if(fa == fs && fb == ft)
        if(siz[fa] + siz[fb] < in[u]) return false; // 若链表s与t相连, 只有边全部删完可以
    return true;
} // 判断从u的a边向u的b边连链表是否可行
void Link(int a, int b) {
    ne[a] = b; 
    la[b] = a;
    int fa = find(a), fb = find(b);
    f[fa] = fb;
    siz[fb] += siz[fa];
} // 连接a, b 维护并查集，删边数
void dfs_find(int u, int edge) { // 在u点, 从edge边进入的
    if(check(edge, t + u, u))
        min_num = min(min_num, u); // 看是否能从这个点结束
    if(ne[edge]) {
        int i = ne[edge];
        int v = to[i];
        dfs_find(v, i ^ 1); // 这条边有后继, 只能走后继边
    } else for(int i = h[u]; i; i = nxt[i]) {
        if(i == edge) continue;
        int v = to[i];
        if(check(edge, i, u))
            dfs_find(v, i ^ 1); // 没有后继, 找一个做后继不冲突的边离开
    }
} // 在链表不发生冲突的情况下找到最小的编号
bool flag;
void dfs_change(int u, int edge) {
    if(u == min_num) {
        flag = true;
        Link(edge, t+u);
        return; // 找到终止点，回溯维护链表
    }
    if(ne[edge]) {
        int i = ne[edge];
        int v = to[i];
        dfs_change(v, i ^ 1);
    } else for(int i = h[u]; i; i = nxt[i]) {
        if(i == edge) continue;
        int v = to[i];
        if(check(edge, i, u)) {
            dfs_change(v, i ^ 1);
            if(flag) {
                Link(edge, i);
                return; // 维护链表
            }
        }
    }
} // 找到终止点并回溯更改
int ans[N];
void init() {
    cnt = 1; // cnt初始化为1, 从2开始编号，边与反向边^=1
    memset(h, 0, sizeof(h));
    memset(ne, 0, sizeof(ne));
    memset(la, 0, sizeof(la));
    memset(in, 0, sizeof(in));
    for(int i = 1; i < N*2; i++) f[i] = i, siz[i] = 0;
} // 初始化
int main() {
    T = read();
    while(T--) {
        init();
        n = read();
        for(int i = 1; i <= n; i++) p[i] = read();
        for(int i = 1; i < n; i++) {
            int x = read(), y = read();
            add_edge(x, y);
            add_edge(y, x);
            in[x]++; in[y]++; // 维护有多少条边
        }
        for(int i = 1; i <= n; i++) { // 贪心
            min_num = n + 1;
            dfs_find(p[i], s + p[i]); // 从p[i]起始
            ans[i] = min_num; // 直接记录到达点即可，不用模拟删边
            flag = false;
            dfs_change(p[i], s + p[i]);
        }
        for(int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}