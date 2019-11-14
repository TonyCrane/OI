/*************************************************************
 *  > Description      : 复赛相关模板
 *  > File Name        : CSP_rp++.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/10 20:59:43
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*-------------------------------- 读入优化 --------------------------------*/
inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}



/*-------------------------------- 存储及逻辑 --------------------------------*/ 
int       --> 2 ^ 31 - 1 --> 2e9  --> 4 bytes
long long --> 2 ^ 63 - 1 --> 9e18 --> 8 bytes
char      --> 2 ^ 7 - 1  --> 127  --> 1 byte

INT_MAX = 0x7fffffff
half_INT_MAX = 0x3f3f3f3f
LONGLONG_MAX = 0x7fffffffffffffff
memset(a, 0, sizeof(a));     0
memset(a, -1, sizeof(a));    -1
memset(a, 0x7f, sizeof(a));  inf
memset(a, 0x3f, sizeof(a));  inf / 2
memset(a, 0x80, sizeof(a));  -inf
memset(a, 0xc0, sizeof(a));  -inf / 2
memset(a, 0x43, sizeof(a));  double inf
memset(a, 0xfe, sizeof(a));  double -inf

1 << n  -->  2^n
n << 1  -->  2n
n >> 1  -->  n / 2 向下取整  //普通 n/2 向0取整

(n >> k) & 1        n在二进制下k位
n & ((1 << k) - 1)  n在二进制下后k位
n xor (1 << k)      n在二进制下k位取反
n | (1 << k)        n在二进制下k位赋值1
n & (~(1 << k))     n在二进制下k位赋值0

(n ^ 1) ^ 1 = n
n --> odd   n xor 1 = n - 1
n --> even  n xor 1 = n + 1

lowbit(x) = x & (~x + 1) = x & -x



/*-------------------------------- STL常用 --------------------------------*/
#include <vector>
vector<int> a;
a.size();
a.empty();
a.clear();
a.push_back();
a.pop_back();
a[ ]
vector<int>::iterator it;
for (it = a.begin(); it != a.end(); ++it) {
    *it;
}

#include <queue>
queue<int> q;
q.push(x);
q.pop();
q.size(); q.empty();
while (!q.empty()) q.pop();

priority_queue<int> pq1; //大根堆
priority_queue<int, vector<int>, greater<int> > pq2; //小根堆
pq1.push(x);   O(log n)
pq1.pop();     O(log n)
pq1.top();     O(1)
struct Node {
    int a, b;
    bool operator < (const Node& x) const {
        return a > x.a;
    }
};
priority_queue<Node> pq3;

#include <deque>
deque<int> dq;
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.push_back();
dq.front(); dq.back();
dq.clear();
dq[ ]

#include <set>
set<int> s;
multiset<int> ms;
bool operator < (const Node& a) const { /* ... */ }
s.size(); s.empty(); s.clear();
set<int>::iterator it;
it++; it--;                 O(log n)
s.insert(x); ms.insert(x);  O(log n)
s.find(x);                  O(log n) //返回迭代器
s.count(x); ms.count(x);    O(k + log n) //元素个数
s.erase(x);                 O(k + log n) //将值为x的全部删去
s.erase(it);                O(log n)     //删除迭代器所指位置
s.lower_bound(x);           O(log n) //查找>=x的最小元素 返回迭代器
s.upper_bound(x);           O(log n) //查找>x 的最小元素 返回迭代器

#include <map>
map<int, int> m;
m.size(); m.empty(); m.clear();
m.insert(pair<int, int>(x, y));
m.erase(pair<int, int>(x, y));
m.erase(it);
m.find(x);    O(log n) //查找键为x的二元组
m[key]        O(log n) //若不存在则会新建,值为广义0

#include <bitset>
bitset<64> bit;
~ & | ^ >> << == !=
bit[ ]
bit.count()

#include <algorithm>
reverse(a + 1, a + 1 + n);
reverse(a.begin(), a.end());
sort(a + 1, a + 1 + n, cmp); 
int id = lower_bound(a + 1, a + 1 + n, x) - a; //大于等于x的最小整数的下标



/*-------------------------------- 基础算法 --------------------------------*/
// 前缀和
for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i]; //l ~ r sum[r] - sum[l - 1];
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
}


// 差分
b[1] = a[1];
for (int i = 1; i <= n; ++i) b[i] = a[i] - a[i - 1];


// 二分
int l = 0, r /*= maxans*/;
while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
        ans = mid;
        l = mid + 1;
    } else r = mid - 1;
}


// 三分
while (l < r) {
    int lmid = l + (r - l) / 3;
    int rmid = r - (r - l) / 3;
    if (F(rmid) > F(lmid)) r = rmid;
    else l = lmid;
}
ans: F(l)


// 离散化
for (int i = 1; i <= n; ++i) old[i] = a[i];
sort(old + 1, old + 1 + n);
int len = unique(old + 1, old + 1 + n) - old - 1;
for (int i = 1; i <= n; ++i) a[i] = lower_bound(old + 1, old + 1 + len, a[i]) - old;
old[a[i]] --> a[i]



/*-------------------------------- 数据结构 --------------------------------*/
// 堆
priority_queue<int> q;


// 并查集
int ufs[maxn], n;
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
void init() { for (int i = 1; i <= n; ++i) ufs[i] = i; }

int find(int x) {
    if (ufs[x] == x) return x;
    int root = find(ufs[x]);
    d[x] += d[ufs[x]];
    return ufs[x] = root;
}
void unionn(int x, int y) {
    x = find(x); y = find(y);
    ufs[x] = y; d[x] = siz[y];
    siz[y] += siz[x];
}


// ST表
int a[maxn], f[maxn][30], n, m;
for (int j = 1; j <= 20; ++j) {
    for (int i = 1; i <= n - (1 << j) + 1; ++i) {
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
}
for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    int k = log(r - l + 1) / log(2);
    printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
}


// 树状数组
int t[maxn], n;
void add(int x, int k) { for (; x <= n; x += x & -x) t[x] += k; }
int ask(int x) { int res = 0; for (; x; x -= x & -x) res += t[x]; return res; }


// 树状数组求逆序对  注意要离散化!!!
for (int i = n; i; --i) {
    ans += ask(a[i] - 1);
    add(a[i], 1);
}


// 树状数组求二位偏序  注意FG要放在一起离散化!!!
for (LL i = n; i; --i) {
    ans += ask(F[i] - 1);
    add(G[i], 1);
}


// 二维树状数组
int t1[maxn][maxn];
int t2[maxn][maxn];
int t3[maxn][maxn];
int t4[maxn][maxn];
void add(int x, int y, int k) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= m; j += j & -j) {
            t1[i][j] += k;
            t2[i][j] += k * x;
            t3[i][j] += k * y;
            t4[i][j] += k * x * y;
        }
    }
}
int ask(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i) {
        for (int j = y; j; j -= j & -j) {
            res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        }
    }
    return res;
}

add(c + 1, d + 1, k);
add(a, d + 1, -k);
add(c + 1, b, -k);
add(a, b, k);
printf("%d\n", ask(c, d) - ask(c, b - 1) - ask(a - 1, d) + ask(a - 1, b - 1));


// 线段树
int n, m, a[maxn];
struct Node {
    int l, r;
    LL dat, laz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) (tree[p].r - tree[p].l + 1)
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];
void pushup(int p) {
    dat(p) = dat(p<<1) + dat(p<<1|1);
}
void pushdown(int p) {
    if (laz(p)) {
        laz(p<<1) += laz(p); laz(p<<1|1) += laz(p);
        dat(p<<1) += len(p<<1) * laz(p);
        dat(p<<1|1) += len(p<<1|1) * laz(p);
        laz(p) = 0;
    }
}
void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        dat(p) = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}
void update(int p, int l, int r, int k) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) += k * len(p);
        laz(p) += k;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}
LL query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return dat(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1; LL ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}


// 莫队
struct Query {
    int l, r, pos, id;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r > b.r;
    return a.r < b.r;
}
for (int i = 1; i <= m; ++i) {
    q[i].id = i;
    q[i].l = read();
    q[i].r = read();
    q[i].pos = q[i].l / len + 1;
}
sort(q + 1, q + 1 + m, cmp); l = 1;
for (int i = 1; i <= m; ++i) {
    while (l < q[i].l) del(l++);
    while (l > q[i].l) add(--l);
    while (r > q[i].r) del(r--);
    while (r < q[i].r) add(++r);
    ans[q[i].id] = Ans;
}


// Hash表
const int N = 2600;
const int mod = (1 << 11) - 1;
struct Hash_Map {
    int ver[N], nxt[N], head[mod + 10], cnt, val[N];
    void add(int u, int v) {
        ver[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt;
    }
    int& operator [] (int v) {
        for (int i = head[v & mod]; i; i = nxt[i]) {
            if (ver[i] == v) return val[i];
        }
        add(v & mod, v);
        return val[cnt];
    }
};


// Trie
struct Trie {
    int ch[maxn][26], sz, val[maxn];
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset( val , 0, sizeof( val ));
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    int search(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) return -1;
            u = ch[u][c];
        }
        return val[u];
    }
};


// 平衡树Treap
struct Treap {
    int l, r, val, dat, cnt, siz;
    #define l(p) a[p].l
    #define r(p) a[p].r
    #define val(p) a[p].val
    #define dat(p) a[p].dat
    #define cnt(p) a[p].cnt
    #define siz(p) a[p].siz
}a[maxn];

int tot, root, n;

int New(int val) {
    val(++tot) = val;
    dat(tot)   = rand();
    cnt(tot)   = 1;
    siz(tot)   = 1;
    return tot;
}

void update(int p) {
    siz(p) = siz(l(p)) + cnt(p) + siz(r(p));
}

void build() {
    New(-inf); New(inf);
    root = 1; r(1) = 2;
    update(root);
}

int getRankByVal(int p, int val) {
    if (p == 0) return 0;
    if (val == val(p)) return siz(l(p)) + 1;
    if (val <  val(p)) return getRankByVal(l(p), val);
    return getRankByVal(r(p), val) + siz(l(p)) + cnt(p);
}

int getValByRank(int p, int rank) {
    if (p == 0) return inf;
    if (siz(l(p)) >= rank) return getValByRank(l(p), rank);
    if (siz(l(p)) + cnt(p) >= rank) return val(p);
    return getValByRank(r(p), rank - siz(l(p)) - cnt(p));
}

void zig(int& p) {
    int q = l(p);
    l(p) = r(q); r(q) = p; p = q;
    update(r(p)); update(p);
}

void zag(int & p) {
    int q = r(p);
    r(p) = l(q); l(q) = p; p = q;
    update(l(p)); update(p);
}

void insert(int& p, int val) {
    if (p == 0) {
        p = New(val);
        return;
    }
    if (val == val(p)) {
        cnt(p)++;
        update(p);
        return;
    }
    if (val < val(p)) {
        insert(l(p), val);
        if (dat(p) < dat(l(p))) zig(p);
    } else {
        insert(r(p), val);
        if (dat(p) < dat(r(p))) zag(p);
    }
    update(p);
}

int getPre(int val) {
    int ans = 1, p = root;
    while (p) {
        if (val == val(p)) {
            if (l(p) > 0) {
                p = l(p);
                while (r(p) > 0) p = r(p);
                ans = p;
            }
            break;
        }
        if (val(p) < val && val(p) > val(ans)) ans = p;
        p = val < val(p) ? l(p) : r(p);
    }
    return val(ans);
}

int getSuf(int val) {
    int ans = 2, p = root;
    while (p) {
        if (val == val(p)) {
            if (r(p) > 0) {
                p = r(p);
                while (l(p) > 0) p = l(p);
                ans = p;
            }
            break;
        }
        if (val(p) > val && val(p) < val(ans)) ans = p;
        p = val < val(p) ? l(p) : r(p);
    }
    return val(ans);
}

void remove(int& p, int val) {
    if (p == 0) return;
    if (val == val(p)) {
        if (cnt(p) > 1) {
            cnt(p)--; update(p);
            return;
        }
        if (l(p) || r(p)) {
            if (r(p) == 0 || dat(l(p)) > dat(r(p))) {
                zig(p); remove(r(p), val);
            } else {
                zag(p); remove(l(p), val);
            }
            update(p);
        } else p = 0;
        return;
    }
    if (val < val(p)) remove(l(p), val);
    else remove(r(p), val);
    update(p);
}



/*-------------------------------- 图论 --------------------------------*/
// 欧拉回路
void dfs(int x) {
    for (int y = 1; y <= maxn; ++y) {
        if (G[x][y]) {
            G[x][y] = 0;
            G[y][x] = 0;
            dfs(y);
        }
    }
    ans[++ansi] = x;
    return;
}
for (int i = 1; i <= maxn; ++i) {
    if (deg[i] % 2) {
        cnt++;
        if (!root) root = i;
    }
}
if (!root) {
    for (int i = 1; i <= maxn; ++i) {
        if (deg[i]) {
            root = i; break;
        }
    }
}
if (cnt && cnt != 2) {
    printf("No Solution\n");
    return 0;
}
dfs(root);


// SPFA
void SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    vis[s] = true; dis[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                if (!vis[e.to]) {
                    q.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
}

// SPFA-SLF优化
if (!vis[e.to]) {
    vis[e.to] = true;
    if (!q.empty() && dis[e.to] < dis[q.front()]) {
        q.push_front(e.to);
    } else {
        q.push_back(e.to);
    }
}

// SPFA判负环
if (!vis[e.to]) {
    vis[e.to] = true;
    q.push(e.to);
    cnt[e.to]++;
}
if (cnt[e.to] >= n) return true;

// 差分约束
a − b ≥ c 从a到b建−c单向边
a − b ≤ c 从b到a建c单向边
a = b     从a到建权值为0的双向边
从0向所有节点建一条边权为0的单向边
求解时,设dis[0]=0,然后以0为源点求单源最短路
如果存在负环,则系统无解
不存在负环,则dis[i]为系统的一组解


// Dijkstra堆优化
struct heap {
    int u, d;
    bool operator < (const heap& a) const {
        return d > a.d;
    }
};
void Dijkstra(int s) {
    priority_queue<heap> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push((heap){s, 0});
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != dis[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                q.push((heap){e.to, dis[e.to]});
            }
        }
    }
}


// Kruskal
struct Edge {
    int from, to, val;
}edges[maxm];
bool cmp(Edge a, Edge b) {
    if (a.val != b.val) return a.val < b.val;
    if (a.from != b.from) return a.from < b.from;
    return a.to < b.to;
}
int ufs[maxn], ans, cnt = 1, n, m;
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
void Kruskal() {
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    sort(edges + 1, edges + 1 + m, cmp);
    for (int i = 1; i <= m; ++i) {
        int x = find(edges[i].from);
        int y = find(edges[i].to);
        if (x != y) {
            ufs[x] = y; cnt++;
            ans += edges[i].val;
        }
    }
}


// Floyd
for (int k = 1; k <= n; ++k) 
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);


// 传递闭包
for (int k = 1; k <= n; ++k) 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            G[i][j] |= G[i][k] & G[k][j];



/*-------------------------------- Tarjan --------------------------------*/
namespace Bridge {
    int dfn[maxn], low[maxn], n, m, num;
    bool bridge[maxn << 1];

    void tarjan(int x, int in_edge) {
        dfn[x] = low[x] = ++num;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to, i);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] > dfn[x]) {
                    bridge[i] = bridge[i ^ 1] = true;
                }
            } else if (i != (in_edge ^ 1)) {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i, 0);
            }
        }
        for (int i = 0; i < edges.size(); i += 2) {
            if (bridge[i]) {
                /* ... */
            }
        }
        return 0;
    }
}

namespace CutPoint {
    int dfn[maxn], low[maxn], n, m, num, root;
    bool cut[maxn];

    void tarjan(int x) {
        dfn[x] = low[x] = ++num;
        int flag = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] >= dfn[x]) {
                    flag++;
                    if (x != root || flag > 1) cut[x] = true;
                }
            } else {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) {
                /* ... */
            }
        }
        return 0;
    }
}

namespace e_DCC {
    using namespace Bridge;
    int c[maxn], dcc;
    
    void dfs(int x) {
        c[x] = dcc;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (c[e.to] || bridge[i]) continue;
            dfs(e.to);
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i, 0);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!c[i]) {
                ++dcc;
                dfs(i);
            }
        }
        /** 
         * 共dcc个边双连通分量
         * 点x属于第c[x]个边双连通分量
         **/
        return 0;
    }
}

namespace e_DCC_ShrinkPoint {
    using namespace e_DCC;
    vector<Edge> nedges;
    vector<int> nG[maxn];
    void nadd(int u, int v) {
        nedges.push_back(Edge(u, v));
        int mm = nedges.size();
        nG[u].push_back(mm - 1);
    }

    int ShrinkPoint() {
        for (int i = 0; i < edges.size(); ++i) {
            Edge& e1 = edges[i];
            Edge& e2 = edges[i ^ 1];
            if (c[e1.to] == c[e2.to]) continue;
            nadd(c[e1.to], c[e2.to]);
        }
    }
}

namespace v_DCC {
    bool cut[maxn];
    int dfn[maxn], low[maxn], n, m, num, root;
    vector<int> dcc[maxn]; int cnt;
    stack<int> s;

    void tarjan(int x) {
        dfn[x] = low[x] = ++num; s.push(x);
        if (x == root && G[x].empty()) {
            dcc[++cnt].push_back(x);
            return;
        }
        int flag = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] >= dfn[x]) {
                    flag++; cnt++; int z;
                    if (x != root || flag > 1) cut[x] = true;
                    do {
                        z = s.top(); s.pop();
                        dcc[cnt].push_back(z);
                    } while (z != e.to);
                    dcc[cnt].push_back(x);
                }
            } else {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i);
            }
        }
        /**
         * 共cnt个点双连通分量
         * 每个v-DCC存储在dcc[i]中
         **/
        return 0;
    }
}

namespace v_DCC_ShrinkPoint {
    using namespace v_DCC;
    vector<Edge> nedges;
    vector<int> nG[maxn];
    void nadd(int u, int v) {
        nedges.push_back(Edge(u, v));
        int mm = nedges.size();
        nG[u].push_back(mm - 1);
    }

    int new_id[maxn], c[maxn];

    int ShrinkPoint() {
        num = cnt;
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) {
                new_id[i] = ++num;
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 0; j < dcc[i].size(); ++j) {
                int x = dcc[i][j];
                if (cut[x]) {
                    nadd(i, new_id[x]);
                    nadd(new_id[x], i);
                } else {
                    c[x] = i;
                }
            }
        }
    }
}

namespace SCC {
    int dfn[maxn], low[maxn], c[maxn];
    int val[maxn], sum[maxn], n, m, num, cnt;
    stack<int> s; bool ins[maxn];
    vector<int> scc[maxn];

    void tarjan(int x) {
        dfn[x] = low[x] = ++num; s.push(x); ins[x] = true;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
            } else if (ins[e.to]) {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
        if (dfn[x] == low[x]) {
            cnt++; int y;
            do {
                y = s.top(); s.pop(); ins[y] = false;
                c[y] = cnt; scc[cnt].push_back(y);
                sum[cnt] += val[y];
            } while (x != y);
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        /**
         * 共cnt个强连通分量
         * x所在的SCC编号为c[x]
         * 编号为i的强连通分量所有点为scc[i]
         **/
        return 0;
    }
}

namespace SCC_ShrinkPoint {
    using namespace SCC;
    vector<Edge> nedges;
    vector<int> nG[maxn];
    void nadd(int u, int v) {
        nedges.push_back(Edge(u, v));
        int mm = nedges.size();
        nG[u].push_back(mm - 1);
    }

    int ShrinkPoint() {
        for (int x = 1; x <= n; ++x) {
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (c[x] == c[e.to]) continue;
                nadd(c[x], c[e.to]);
            }
        }
    }
}



/*-------------------------------- 树上问题 --------------------------------*/
namespace dep {
    bool vis[maxn]; int dep[maxn];
    vector<int> son[maxn];
    void dfs(int x) {
        vis[x] = true;
        for (int i = 0; i < son[x].size(); ++i) {
            int y = son[x][i];
            if (vis[y]) continue;
            dep[y] = dep[x] + 1;
            dfs(y);
        }
    }
}

namespace center {
    bool vis[maxn]; int size[maxn], n, ans, pos;
    vector<int> son[maxn];
    void dfs(int x) {
        vis[x] = true; size[x] = 1;
        int max_part = 0;
        for (int i = 0; i < son[x].size(); ++i) {
            int y = son[x][i];
            if (vis[y]) continue;
            dfs(y);
            size[x] += size[y];
            max_part = max(max_part, size[y]);
        }
        max_part = max(max_part, n - size[x]);
        if (max_part < ans) {
            ans = max_part; 
            pos = x;
        }
    }
}

namespace diameter {
    int ans;
    int dfs(int x) {
        int res1 = 0, res2 = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            res2 = max(res2, dfs(e.to) + e.val);
            if (res2 > res1) swap(res1, res2);
        }
        ans = max(ans, res1 + res2);
        return res1;
    }
}

namespace LCA {
    int f[maxn][20], d[maxn];
    int n, m, t;
    void bfs(int s) {
        queue<int> q;
        q.push(s); d[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (d[e.to]) continue;
                d[e.to] = d[x] + 1;
                f[e.to][0] = x;
                for (int j = 1; j <= t; ++j) {
                    f[e.to][j] = f[f[e.to][j - 1]][j - 1];
                }
                q.push(e.to);
            }
        }
    }
    int lca(int x, int y) {
        if (d[x] > d[y]) swap(x, y);
        for (int i = t; i >= 0; --i) {
            if (d[f[y][i]] >= d[x]) y = f[y][i];
        }
        if (x == y) return x;
        for (int i = t; i >= 0; --i) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }
}

namespace LCA_TreeChainSplit {
    int n, m, s;
    int dep[maxn], siz[maxn], fa[maxn], son[maxn], top[maxn];
    void dfs1(int x, int f, int depth) {
        dep[x] = depth; fa[x] = f;
        siz[x] = 1; int maxs = -1;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (e.to == f) continue;
            dfs1(e.to, x, depth + 1);
            siz[x] += siz[e.to];
            if (siz[e.to] > maxs) {
                son[x] = e.to;
                maxs = siz[e.to];
            }
        }
    }
    void dfs2(int x, int topf) {
        top[x] = topf;
        if (!son[x]) return;
        dfs2(son[x], topf);
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (e.to == fa[x] || e.to == son[x]) continue;
            dfs2(e.to, e.to);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        return x;
    }
    /* dfs1(root, 0, 1); dfs2(root, root); */
}



/*-------------------------------- 数学 --------------------------------*/
// 最大公约数
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}


// 扩展欧几里得
void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}


// 筛质数
LL vis[maxn];
LL prime[maxn], sum[maxn], num;
void getprime(LL n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= n; ++i) {
        if (vis[i] == 0) {
            vis[i] = i;
            prime[++num] = i;
        }
        for (int j = 1; j <= num; ++j) {
            if (prime[j] > vis[i] || prime[j] > n / i) break;
            vis[i * prime[j]] = prime[j];
        }
    }
}


// 快速乘
LL mul_mod(LL a, LL b, LL n){
    LL res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}


// 快速幂
LL pow_mod(LL a, LL p, LL n){
    int res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
}


// 欧拉函数
int phi(int n) {
    int m = (int)sqrt(n + 0.5); int ans = n;
    for (int i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}


// 乘法逆元
LL inv(LL a, LL n) {
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}
p为质数时, inv=a^(p-2);


// 求正约数集合
vector<int> fac;
for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
        fac.push_back(i);
        if (i != n / i) fac.push_back(n / i);
    }
}


// 斐波那契/矩阵
struct Matrix {
    LL mat[2][2];
    Matrix() { memset(mat, 0, sizeof(mat)); }
    Matrix operator * (const Matrix& a) const {
        Matrix res; memset(res.mat, 0, sizeof(res.mat));
        for (LL i = 0; i < 2; ++i) {
            for (LL j = 0; j < 2; ++j) {
                for (LL k = 0; k < 2; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
}Base, Fib;
void Matrix_pow(LL pow) {
    while (pow) {
        if (pow & 1) Fib = Fib * Base;
        Base = Base * Base;
        pow >>= 1;
    }
}
Base.mat[0][0] = 1; Base.mat[0][1] = 1;
Base.mat[1][0] = 1; Base.mat[1][1] = 0;
Fib.mat[0][0] = 1; Fib.mat[0][1] = 1;
Matrix_pow(n - 2);
fib(n) = Fib.mat[0][0];



/*-------------------------------- 注意 --------------------------------*/
- 函数中变量赋初值
- 循环变量别写错
- 别忘开long long
- mod别忘处理负数
- freopen别注释
- freopen别写错
- rand别忘srand
- 注意double
- 注意有向边无向边
- 算空间不要MLE
- 二维数组行列别搞反
- 数组下标别越界
- 别忘判断除以0
- 注意运算符优先级
- 注意判循环边界
- dfs注意终止
- 注意强制转换类型
- 快读别写错
- 写过的debug代码都不要删

<=10              n
10 ~ 20           3^n
10 ~ 25           2^n
30 ~ 50           2^(n/2)
<= 100            搜索
100 ~ 500         n^3
1000 ~ 5000       n^2
100000 ~ 500000   nlog n
>=500000N         n / log n / 1

静态查错
- 是否写上了 using namespace std
- 数组开得是否够大？
- 变量类型是否正确？
- memset 时， 所填的 sizeof(x) 的 x 是不是匹配?大小是不是正确？
- 外层循环与内层循环的 i,j 是不是混用了
- 输入 数据都输入了吗
- 这个程序是在执行你想让它执行的步骤吗
- 变量是否重名

set number
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set laststatus=2
set mouse=a
set scrolloff=4
inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O



/*---------------------------- CSP2019-S/II RP++  ----------------------------*/